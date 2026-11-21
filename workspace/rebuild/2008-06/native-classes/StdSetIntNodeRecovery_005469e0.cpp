// native-flags: /Od /Ob0 /GS /EHsc /MD
// Inactive native 2008-06 recovery: std::_Uninit_fill_n 005469e0 for the std::set<int> node pointer
// (authentic VC9 <memory>; the loop calls allocator<_Node*>::construct 00546d00, stride 4).
#include <memory>
#include <set>
#include <xmemory>

namespace {
struct SetIntNodeAccess : std::_Tree_nod<std::_Tset_traits<int, std::less<int>, std::allocator<int>, false> >
{
	typedef _Node* NodePtr;
};
typedef SetIntNodeAccess::NodePtr NodePtr;
}

template void std::_Uninit_fill_n<NodePtr*, unsigned int, NodePtr, std::allocator<NodePtr> >(NodePtr*, unsigned int,
	const NodePtr&, std::allocator<NodePtr>&, std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag);
