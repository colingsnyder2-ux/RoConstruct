// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Elem { std::string s; int v; };
Elem* copy_range(Elem* first, Elem* last, Elem* dest)
{
    while (first != last)
        *--dest = *--last;
    return dest;
}
