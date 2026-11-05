// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <set>

struct Value { char bytes[0x38]; };

typedef std::_Tree<std::_Tset_traits<Value, std::less<Value>, std::allocator<Value>, false> > Tree;
template void Tree::_Lrotate(Tree::_Nodeptr);
