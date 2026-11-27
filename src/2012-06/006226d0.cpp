// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <vector>
struct WedgeBuilder { int pad; std::vector<int> v; void add(const int& x); };
void WedgeBuilder::add(const int& x) { v.push_back(x); }
