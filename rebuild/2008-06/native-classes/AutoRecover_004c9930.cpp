// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: boost::multi_index::detail::ordered_index_node_impl::restore (+ inlined link).
struct Local_004c9930_Node;

struct Local_004c9930_ParentRef {
    unsigned int* r;
    operator Local_004c9930_Node*() const {
        return (Local_004c9930_Node*)(*r & ~1u);
    }
    Local_004c9930_ParentRef& operator=(Local_004c9930_Node* p) {
        *r = (unsigned int)p | (*r & 1u);
        return *this;
    }
};

struct Local_004c9930_Node {
    unsigned int parentcolor_;
    Local_004c9930_Node* left_;
    Local_004c9930_Node* right_;

    Local_004c9930_ParentRef parent() { Local_004c9930_ParentRef p; p.r = &parentcolor_; return p; }
    Local_004c9930_Node*& left() { return left_; }
    Local_004c9930_Node*& right() { return right_; }
};

extern "C" void fn_004c6710(Local_004c9930_Node*& x);
extern "C" void fn_004c6870(Local_004c9930_Node* x, Local_004c9930_ParentRef root);

static inline void link_node(Local_004c9930_Node* x, bool to_right, Local_004c9930_Node* position, Local_004c9930_Node* header)
{
    if (!to_right) {
        position->left() = x;
        if (position == header) {
            header->parent() = x;
            header->right() = x;
        } else if (position == header->left()) {
            header->left() = x;
        }
    } else {
        position->right() = x;
        if (position == header->right()) {
            header->right() = x;
        }
    }
    x->parent() = position;
    x->left() = 0;
    x->right() = 0;
    fn_004c6870(x, header->parent());
}

extern "C" void fn_004c9930(Local_004c9930_Node* x, Local_004c9930_Node* position, Local_004c9930_Node* header)
{
    if (position->left() == 0 || position->left() == header) {
        link_node(x, false, position, header);
    } else {
        fn_004c6710(position);
        link_node(x, true, position, header);
    }
}
