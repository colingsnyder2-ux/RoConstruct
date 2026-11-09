// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet roc_profiled_ordered_index_8a30f7d3ed242e0d.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/multi_index/detail/ord_index_node.hpp>

namespace boost {
namespace multi_index {
namespace detail {

void roc_ordered_index_increment(ordered_index_node_impl*& node)
{
    ordered_index_node_impl::increment(node);
}

void roc_ordered_index_decrement(ordered_index_node_impl*& node)
{
    ordered_index_node_impl::decrement(node);
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

ordered_index_node_impl* roc_ordered_index_minimum(
    ordered_index_node_impl* node)
{
    return ordered_index_node_impl::minimum(node);
}

ordered_index_node_impl* roc_ordered_index_maximum(
    ordered_index_node_impl* node)
{
    return ordered_index_node_impl::maximum(node);
}

void roc_ordered_index_rebalance(
    ordered_index_node_impl* node,
    ordered_index_node_impl::parent_ref root)
{
    ordered_index_node_impl::rebalance(node, root);
}

void roc_ordered_index_link(
    ordered_index_node_impl* node,
    ordered_index_side side,
    ordered_index_node_impl* position,
    ordered_index_node_impl* header)
{
    ordered_index_node_impl::link(node, side, position, header);
}

ordered_index_node_impl* roc_ordered_index_rebalance_for_erase(
    ordered_index_node_impl* node,
    ordered_index_node_impl::parent_ref root,
    ordered_index_node_impl*& leftmost,
    ordered_index_node_impl*& rightmost)
{
    return ordered_index_node_impl::rebalance_for_erase(
        node, root, leftmost, rightmost);
}

void roc_ordered_index_restore(
    ordered_index_node_impl* node,
    ordered_index_node_impl* position,
    ordered_index_node_impl* header)
{
    ordered_index_node_impl::restore(node, position, header);
}

}
}
}
