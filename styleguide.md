# The Shitty Style Guide

## Motivation

Most code is written to be used. This style guide is for code that should never,
ever, be used in a production setting. The code should be shitty in order to
make sure users don't use the code in production without completely rewriting
it. The code should be easy to use when writing code for competitive
programming.

## Organization

All code should be self contained within a single header-file. Do not include
any file from any other file in this project. Every single header should be
completely self hosted, just copy paste code when needed.

## Types

No standard type names should be used. Every type in use should be defined with
a typedef. All typedefs should be defined directly after includes. No type name
used in an externally facing function should be longer than four characters.
Always use unsigned types when possible.

Internally used data structures should have typedefs explaining what the data
is, for example: 

```c++ 
typedef vector< vector<l> > adjmat; 
```

If the code is using `auto`, another typedef should be created in most cases.

The following typedefs are suggested to use in most code:

```c++
typedef uint64_t ul;
typedef int64_t l;
typedef double fp;
```

Unused typedefs should be removed from the header.

## Classes

Classes are nice. Always make all members public. Always specify what members
are supposed to be public and private. Don't use `virtual`.

```c++
class Fenwick {
public:
  Fenwick(ul size);
  Fenwick(ul size) { ...implementation... };
  void add (ul index, l diff) { ...implementation... };
  l sum (ul begin, ul end) { ...implementation... };
//private:
  l cumulative_sum(ul begin) { ...implementation... };
  vector<l> data;
};
```

## Const

Sprinkle the code with `const`, but *never*, **ever**, limit what the user can
do with any exposed data. So, make function arguments `const`, make variables
with limited scope `const`, but never limit any return value with `const`.

## Performance

Performance should be decent. Do things in place if possible, sprinkle some
`inline`s around the code. Prefer readability and code clarity over performance,
but try to do both. Optionally provide a fast, but unreadable, version in a
comment. Or the other way around.

## Tests

Automated tests may be used, but it's good enough if everything seems to work
with manual testing. If automated testing is used, no testing frameworks apart
from shell scripts should be used.

## Usage Examples

Examples of usage may be provided in a separate `.cpp` files. These files should
be used for testing.

## Error handling

The code should contain no error handling at all. All function arguments should
be considered to be valid.

## Templates

Templates are not to be used. Use typedefs instead.

## Defines

Don't define strange things. Use `inline` instead of macros taking arguments.

## Constants

Use `#define`.

## The C++ standard library

Use whatever is in it, but most things in `<algorithm>` should be avoided. Most
things where one has to write `q.begin(), q.end()` should be avoided.

## Warnings and compilation

All code should compile without warnings or notes using `gcc -pedantic -Wall
-Wextra -Werror`.

## Includes

All headers shall begin with 
```c++
#include <bits/stdc++.h>
using namespace std;
```

## Casts

Use C-style casts. They are shorter.

## Comments

All headers shall include a good, preferably academic, reference to the
algorithm or data structure implemented in the header. This reference should be
provided as easily copy-pasted bibtex. Code should remain uncommented except
when doing really weird stuff, such as appending vectors with `std::algorithm`.
Jokes, memes and complaints about how shitty C++ is should be inserted at the
authors discretion.

## Names

Variables in small scopes with an obvious purpose should be given short and
useless names such as `q`, `x` or `p`. Lambdas should in most cases be named
`f`. Functions should have names that makes sense in the context of the
algorithm, but not necessarily out of context. Prefer to use similar variable
and function names as in any used academic references.

## Code Clarity

The code should be shitty, not bad. WTFs per minute should still be a valid
quality measurement. Code should be read along with its reference.
