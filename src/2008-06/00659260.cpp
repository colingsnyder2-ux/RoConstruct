// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { struct Item { int pad0; int a; int b; int c; int d; int e; int f; bool g; Item(int c, int d); };
Item::Item(int c_, int d_) : a(0), b(0), c(c_), d(d_), e(-1), f(-1), g(false) {} }
