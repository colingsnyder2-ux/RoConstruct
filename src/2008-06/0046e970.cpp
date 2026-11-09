// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct S {
    int first;
    int second;
    std::string name;
    std::string value;

    S(int a, int b, std::string n, std::string v);
};

S::S(int a, int b, std::string n, std::string v)
    : first(a), second(b), name(n), value(v)
{
}
