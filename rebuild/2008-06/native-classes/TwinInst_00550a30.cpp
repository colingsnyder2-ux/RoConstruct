// native-flags: /Od /Ob0 /GS /EHsc /MD
// 00550a30: explicit instantiation for the _Tree_nod<_Tmap_traits<int, int>> constructor evidence.
#include <map>
template class std::map<int, int>;
