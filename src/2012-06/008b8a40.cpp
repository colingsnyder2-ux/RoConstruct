// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

#include <vector>
struct X { double d[4]; X(); X(const X&); X& operator=(const X&); ~X(); };
struct E { X x; int i; };
template class std::vector<E>;

