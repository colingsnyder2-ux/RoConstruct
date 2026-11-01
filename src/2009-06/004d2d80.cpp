// from server: 100% by EspClaude
// roc 2009-06 004d2d80
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class Self;
class Target { public: void operator()(Self* self, std::string a, int b, std::string c); };
template<int I> struct arg {};
struct Refs {
    const std::string* a; const int* b; const std::string* c;
    const std::string& operator[](arg<1>) const { return *a; }
    const int& operator[](arg<2>) const { return *b; }
    const std::string& operator[](arg<3>) const { return *c; }
};
template<class R> struct type {};
class Self {
public:
    template<class F, class A> void operator()(type<void>, F& f, A& a, int)
    {
        f(this, a[arg<1>()], a[arg<2>()], a[arg<3>()]);
    }
};
template void Self::operator()(type<void>, Target&, Refs&, int);
}
