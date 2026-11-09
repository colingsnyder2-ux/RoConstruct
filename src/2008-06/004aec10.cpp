// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct E { int v[11]; };
#include <map>
struct K; template class std::map<K*, E>;