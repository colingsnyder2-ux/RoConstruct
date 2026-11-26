// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <vector>
#include <utility>
struct A { int f0; std::vector<std::pair<int,int> > v; void func(); };
void A::func() { v.clear(); }