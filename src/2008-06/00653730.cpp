// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
#include <set>
struct T;
template class std::map<int, std::set<T*> >;
