// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
#include <hash_map>
typedef stdext::hash_map<int,int> M;
template struct stdext::_Hash<stdext::_Hmap_traits<int,int,stdext::hash_compare<int,std::less<int> >,std::allocator<std::pair<const int,int> >,false> >::_List_position;
