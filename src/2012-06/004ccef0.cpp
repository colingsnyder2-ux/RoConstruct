// from server: 100% by sophus
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <set>

struct Value { char bytes[0x1c]; };
// _Myhead at +0x10: comparator carries 4 bytes of state.
struct Less { int state; bool operator()(const Value&, const Value&) const; };

typedef std::_Tree<std::_Tset_traits<Value, Less, std::allocator<Value>, false> > Tree;
template void Tree::_Lrotate(Tree::_Nodeptr);
