// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_SECURE_SCL=0
#include <map>

struct Value { int data[21]; };

template class std::_Tree<std::_Tmap_traits<int, Value, std::less<int>, std::allocator<std::pair<const int, Value> >, false> >;
