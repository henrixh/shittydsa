#include <fenwick.h>
// Implements a solution to
// https://open.kattis.com/problems/fenwick

int main(int, char **)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ul size, ops;
  cin >> size >> ops;

  Fenwick fen {size};

  char op;
  ul index;
  l diff;
  for (ul i {0}; i < ops; ++i) {
    cin >> op;
    if (op == '+') {
      cin >> index >> diff;
      fen.add(index, diff);
    }

    if (op == '?') {
      cin >> index;
      cout << fen.sum(0, index) << "\n";
    }
  }
  return 0;
}
