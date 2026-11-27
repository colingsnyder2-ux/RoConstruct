// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /EHsc /MT
#include <vector>
#include <algorithm>
struct V3 { float x, y, z; };
struct SV { int a; int b; std::vector<V3> v; };
SV* f(SV* first, SV* last, SV* dest) { return std::copy(first, last, dest); }
SV* g(SV* first, SV* last, SV* dest) { return std::copy_backward(first, last, dest); }
