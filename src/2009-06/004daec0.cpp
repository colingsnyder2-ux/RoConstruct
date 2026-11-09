// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
struct Val { double d; char pad[0x140]; };
template class std::_Tree<std::_Tmap_traits<int,Val,std::less<int>,std::allocator<std::pair<const int,Val> >,false> >;
