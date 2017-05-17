#include <bits/stdc++.h>
using namespace std;

typedef int32_t l;
typedef uint32_t ul;
typedef double fp;
typedef complex<fp> cd;
typedef vector<cd> vc;
typedef vector<fp> vd;

ul inline lb(l x) {
  ul res { 0 };
  while(x) {
    x >>= 1;
    res++;
  }
  return res;
}

bool inline ispoweroftwo(size_t n) {
  return ((n != 0) && !(n & (n - 1)));
}

// Pad `v` to a length that is a power of two.
void pad(vc& v) {
  while (!ispoweroftwo(v.size())) {
    v.push_back({0,0});
  }
}

// ul bitreverse(ul in) {
//   ul out { in };
//   for (ul i { 0 }; i < sizeof(ul) * 8; ++i) {
//     out <<= 1;
//     out |= in & 1;
//     in >>= 1;
//   }
//   return out;
// }

// Magic stolen from http://aggregate.org/MAGIC/#Bit%20Reversal
ul bitreverse(ul x) {
  x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
	x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
	x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
	x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
	return((x >> 16) | (x << 16));
}

vc bitreversecopy(vc& xs) {
  vc res;
  ul size = xs.size();
  ul lb_size = (ul)lb(size);
  res.assign(size, {});
  for (ul i { 0 }; i < size; i++) {
    ul index = (bitreverse(i) >> (sizeof(ul)*8 - lb_size + 1));
    cd r { xs[i] };
    res[index] = r;
  }
  return res;
}


vc transform(vc& xs, bool inverse) {
  ul n { (ul)xs.size() };
  ul lb_n { lb(n)  };
  vc A { bitreversecopy(xs) };

  if (inverse) {
    for (auto&& a : A) {
      a /= (fp)n;
    }
  }

  // Pseudocode shamelessly stolen from wikipedia #magic
  ul m { 1 };
  for (ul s { 1 }; s < lb_n; s++) {
    m *= 2;
    cd twiddlechange;
    if (inverse) {
      twiddlechange = exp(cd(2 * M_PI/(fp)m, 0)*cd(0,1));
    } else {
      twiddlechange = exp(cd(-2 * M_PI/(fp)m, 0)*cd(0,1));
    }

    for (ul k { 0 }; k < n; k += m) {
      cd twiddle {1,0};
      for (ul j { 0 }; j < m/2; ++j) {
        cd t = twiddle * A[k + j + m/2];
        cd u = A[k + j];
        A[k + j] = u + t;
        A[k + j + m/2] = u - t;
        twiddle *= twiddlechange;
      }
    }
  }
  return A;
}

vc fft(vc& x){
  return transform(x, false);
}

vc ifft(vc& x){
  return transform(x, true);
}

vd convolve(vd& as, vd& bs) {
  vc acs {};
  vc bcs {};
  acs.reserve(as.size() + bs.size());
  bcs.reserve(as.size() + bs.size());

  // Increase complexity
  for(auto a : as) {
    acs.push_back(a);
  }
  for(auto b : bs) {
    bcs.push_back(b);
  }

  for (ul i = 0; i < bs.size(); ++i) {
    acs.push_back({0,0});
  }
  for (ul i = 0; i < as.size(); ++i) {
    bcs.push_back({0,0});
  }

  pad(acs);
  pad(bcs);

  // autobots_roll_out.gif
  vc ACS = fft(acs);
  vc BCS = fft(bcs);

  vc RES;
  RES.reserve(ACS.size());
  l n = ACS.size();
  for (l i { 0 };  i < n; ++i) {
    RES.push_back(ACS[i] * BCS[i]);
  }

  // Get real
  vc res_c { ifft(RES) };
  vd res {};
  res.reserve(res_c.size());
  for(auto r : res_c) {
    res.push_back(r.real());
  }
  return res;
}
