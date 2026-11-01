// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
namespace Wml {
class R {
public:
    R(int a, int b);
    R f(int n);
    static R NONE;
    int first;
    int count;
};
R R::f(int n) {
    if (this != &NONE) return *this;
    return R(0, n);
}
}
