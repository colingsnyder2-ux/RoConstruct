// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
namespace Wml {
class R {
public:
    R(int a, int b);
    int first;
    int count;
};
R::R(int a, int b) { first = a; count = b - a; }
}
