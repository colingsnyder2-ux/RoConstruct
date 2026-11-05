// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>

// std::string::operator=(const char*) is imported from MSVCP80 (call through IAT).
struct S_func_00596d00 {
    char pad0[0xe8];
    double m_d;
    std::string m_str;
    void f(const bool& v);
};

void S_func_00596d00::f(const bool& v)
{
    m_str = v ? "true" : "false";
    m_d = v ? 1 : 0;
}
