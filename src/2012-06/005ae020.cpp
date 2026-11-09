// roc-cl: 30729
// roc-lang: cpp
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet roc_profiled_ordered_index_f1cfe071f3a26b00.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/multi_index/detail/ord_index_node.hpp>

namespace boost {
namespace multi_index {
namespace detail {

void roc_ordered_index_increment(ordered_index_node_impl*& node)
{
    ordered_index_node_impl::increment(node);
}

void roc_ordered_index_rotate_left(
    ordered_index_node_impl* node,
    ordered_index_node_impl::parent_ref root)
{
    ordered_index_node_impl::rotate_left(node, root);
}

void roc_ordered_index_rotate_right(
    ordered_index_node_impl* node,
    ordered_index_node_impl::parent_ref root)
{
    ordered_index_node_impl::rotate_right(node, root);
}

}
}
}
