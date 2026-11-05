// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
#include <hash_map>
typedef stdext::_Hmap_traits<int, int, stdext::hash_compare<int, std::less<int> >, std::allocator<std::pair<const int, int> >, false> Traits;
template void stdext::_Hash<Traits>::_Init(stdext::_Hash<Traits>::size_type);
