// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
namespace Wml {
class A {
public:
    void g(int a, int b);
    void f(int a);
    int m0;
    int m4;
};
void A::f(int a) { g(a, m4); }
}
