#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000000
typedef bitset<SIZE> bf;

typedef uint64_t ul;
typedef int64_t l;

/*
@misc{ wiki:Sieve_of_Eratosthenes,
   author = "Wikipedia",
   title = "{Sieve of Eratosthenes} --- {W}ikipedia{,} The Free Encyclopedia",
   year = "2017",
   howpublished = {\url{http://en.wikipedia.org/w/index.php?title=Sieve\%20of\%20Eratosthenes&oldid=780000977}},
   note = "[Online; accessed 17-May-2017]"
 }
*/

class primesieve {
public: //private:
  bf p;
public:
  primesieve(ul size) {
    p.flip();
    p[0] = false;
    ul increment = 3;

    ul limit = (ul)sqrt((double)size);
    while(increment < limit) {
      for(ul i = increment*increment; i < size; i += increment*2) {
        p[i/2] = false;
      }

      do {
        increment += 2;
      } while(increment < limit && !p[increment/2]);
    }
  };

  inline bool is_prime(const ul q) {
    return (q==2 || ( (0x1 & q) && (p[q/2]) ));
  };
};
