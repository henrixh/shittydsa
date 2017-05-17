#include "fft.h"

// First line: length of polynoms, space separated
// Read two lines of floats from stdin and convolve them.
int main(int, char**) {
  ul len_a, len_b;
  cin >> len_a >> len_b;
  vd a,b;

  fp x;
  for (ul i { 0 }; i < len_a; ++i) {
    cin >> x;
    a.push_back(x);
  }

  for (ul i { 0 }; i < len_b; ++i) {
    cin >> x;
    b.push_back(x);
  }

  vd r { convolve(a,b) };
  r.resize(len_a+len_b);
  for (auto x : r) {
    cout << round(x) << '\n';
  }

}
