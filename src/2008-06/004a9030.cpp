// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct K { int words[7]; bool operator<(const K&) const; };
#include <map>
template class std::map<K,int>;
