// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX { namespace Network {
struct NameT { std::string s; NameT(const std::string& x) : s(x) {} };
class Base {
public:
    Base(void* owner, NameT a, int b);
    ~Base();
    char pad[0x20];
};
struct Info { std::string a; int b; };
class Derived : public Base {
public:
    Derived(void* owner, Info info, std::string c);
    struct Name { std::string s; Name(const std::string& x) : s(x) {} } name;
};
Derived::Derived(void* owner, Info info, std::string c)
    : Base(owner, info.a, info.b), name(c)
{
}
}}
