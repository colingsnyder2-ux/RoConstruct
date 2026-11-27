// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <vector>
struct X { int a; std::vector<int> v; ~X() { a = 0; } };
struct S { void destroy(X* p); };
void S::destroy(X* p) { p->~X(); }
