// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
struct StrValue { std::string t; };
struct Arg1 {};
class Base {
public:
    Base(int a, Arg1 b, StrValue name);
protected:
    int a;
    StrValue name;
};
class Derived : public Base {
public:
    Derived(int a, Arg1 b, StrValue name, int c, int d);
private:
    int c;
    int d;
};
Derived::Derived(int a, Arg1 b, StrValue name, int c, int d)
    : Base(a, b, name), c(c), d(d)
{
}
}
