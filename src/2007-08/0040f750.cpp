// from server: 100% by EspClaude
// roc 2007-08 0040f750  std::copy-style fill of {std::string; int; int} elements
#include <string>

struct Elem {
    std::string s;
    int a;
    int b;
};

void copy_elems(Elem* first, Elem* last, const Elem& src)
{
    for (; first != last; ++first)
        *first = src;
}
