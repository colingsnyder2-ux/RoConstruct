// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class S {
public:
    void a(std::string s);
    void b(std::string s);
    void f(std::string s);
};
void S::f(std::string s) { a(s); b(s); }
}
