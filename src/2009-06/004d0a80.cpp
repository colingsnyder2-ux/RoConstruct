// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Str { std::string s; };
struct T : std::string { T(int b, Str s); };
struct R {
    int a;
    T s;
    R(int a_, const T& s_) : a(a_), s(s_) {}
};
R make(int a, int b, Str s)
{
    return R(a, T(b, s));
}
