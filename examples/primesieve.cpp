#include "primesieve.h"

int main(int, char**) {
  primesieve ps(10000);
  for (ul i  { 0 }; i < 10000; ++i) {
    if (ps.is_prime(i)) cout << i << '\n';
  }
}
