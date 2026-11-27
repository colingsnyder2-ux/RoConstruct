// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <string>
struct S { void f(std::string& s); };
void S::f(std::string& s) {
    for (size_t i = 0; i < s.size(); ++i) s[i] = s[i] ^ 0x55;
}
