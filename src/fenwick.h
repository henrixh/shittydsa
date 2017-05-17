#include <bits/stdc++.h>
using namespace std;
typedef unsigned long ul;
typedef long l;

/*
  @misc{ wiki:Fenwick_tree,
  author = "Wikipedia",
  title = "{Fenwick tree} --- {W}ikipedia{,} The Free Encyclopedia",
  year = "2017",
  howpublished = {\url{http://en.wikipedia.org/w/index.php?title=Fenwick\%20tree&oldid=771724097}},
  note = "[Online; accessed 17-May-2017]"
  }
*/

l inline lsb(const l n) {
  return ((n) & -(n));
}

class Fenwick
{
public: //private:
  l cumulative_sum(ul index) {
    l res {};
    while (index) {
      res += data[index -1];
      index -= lsb(index);
    }
    return res;
  };

  vector<l> data;

public:
  Fenwick(ul size) {
    data.assign(size, {});
  };

  void add(ul index, l diff) {
    while (index < data.size()) {
      data[index] += diff;
      index += lsb(index + 1);
    }
  };

  l sum(ul begin, ul end) {
    return cumulative_sum(end) - cumulative_sum(begin);
  };
};
