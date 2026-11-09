// from server: 100% by EspClaude
// roc 2009-06 004d08c0
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class Instance;
typedef void (*Fn)(Instance*, std::string, int, std::string);
template<int I> struct arg {};
template<class R> struct type {};
struct Args1 {
    Instance* const* a1;
    Instance* const& operator[](arg<1>) const { return *a1; }
};
class List4 {
public:
    std::string a2_;
    int a3_;
    std::string a4_;
    const std::string& operator[](const std::string& v) const { return v; }
    template<class F, class A> void operator()(type<void>, F& f, A& a, int)
    {
        f(a[arg<1>()], a2_, a3_, a4_);
    }
};
template void List4::operator()(type<void>, Fn&, Args1&, int);
}
