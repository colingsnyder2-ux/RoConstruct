// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <set>

struct Value28 { char bytes[0x28]; };

typedef std::_Tree<std::_Tset_traits<Value28, std::less<Value28>, std::allocator<Value28>, false> > Tree28;
template void Tree28::_Lrotate(Tree28::_Nodeptr);
