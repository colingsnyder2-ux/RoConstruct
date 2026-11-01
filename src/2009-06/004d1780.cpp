// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost {
template<class F, class A1, class A2, class A3, class A4> struct bind_t {
    F f; A2 a2; A3 a3; A4 a4;
};
template<class F, class A1, class A2, class A3, class A4>
bind_t<F, A1, A2, A3, A4> bind(F f, A1 a1, A2 a2, A3 a3, A4 a4);
}
namespace boost { template<int I> struct arg {}; }
namespace { boost::arg<1> _1; }
struct Context;
void handler(Context* ctx, std::string a, int n, std::string b);
class Poster {
    void* impl;
public:
    template<class F> void post(F f);
    void send(std::string a, int n, std::string b);
};
void Poster::send(std::string a, int n, std::string b)
{
    post(boost::bind(&handler, _1, a, n, b));
}
