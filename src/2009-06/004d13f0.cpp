// from server: 100% by EspClaude
// roc 2009-06 004d13f0
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
struct Value { std::string t; };
struct Storage1 { Value a1_; };
struct List1 : Storage1 {};
struct Bind { void (*f_)(std::string); List1 l_; };
class Impl { public: void handle(Bind e); };
class Owner {
    Impl* impl;
public:
    void handle(Bind e);
};
void Owner::handle(Bind e)
{
    if (impl)
        impl->handle(e);
}
}
