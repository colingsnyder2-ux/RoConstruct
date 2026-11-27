// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#define _SECURE_SCL 0
#define _HAS_ITERATOR_DEBUGGING 0
#include <map>
static std::map<int,int> g;
int use(){ return (int)g.size(); }