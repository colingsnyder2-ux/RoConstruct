// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct S {
    std::string first;
    int value;
    std::string second;

    S(std::string a, int n, std::string b);
};

S::S(std::string a, int n, std::string b)
    : first(a), value(n), second(b)
{
}
