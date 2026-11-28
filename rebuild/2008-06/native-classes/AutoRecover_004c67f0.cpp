// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: boost::multi_index::detail::ordered_index_node_impl::rotate_right
// with compressed parent/colour word (low bit = colour).
struct Local_004c67f0_Node;

struct Local_004c67f0_ParentRef {
    unsigned int* pc;

    Local_004c67f0_Node* pointer() const { return (Local_004c67f0_Node*)(*pc & 0xfffffffeu); }

    Local_004c67f0_ParentRef& operator=(Local_004c67f0_Node* p) {
        *pc = (unsigned int)p | (*pc & 1u);
        return *this;
    }
    Local_004c67f0_ParentRef& operator=(const Local_004c67f0_ParentRef& r) {
        *pc = (*pc & 1u) | (*r.pc & 0xfffffffeu);
        return *this;
    }
};

struct Local_004c67f0_Node {
    unsigned int parentcolor;
    Local_004c67f0_Node* leftp;
    Local_004c67f0_Node* rightp;

    Local_004c67f0_ParentRef parent() { Local_004c67f0_ParentRef r; r.pc = &parentcolor; return r; }
    Local_004c67f0_Node*& left() { return leftp; }
    Local_004c67f0_Node*& right() { return rightp; }
};

extern "C" void fn_004c67f0(Local_004c67f0_Node* x, unsigned int* rootpc)
{
    Local_004c67f0_ParentRef root;
    root.pc = rootpc;

    Local_004c67f0_Node* y = x->left();
    x->left() = y->right();
    if (y->right() != 0) {
        y->right()->parent() = x;
    }
    y->parent() = x->parent();
    if (x == root.pointer()) {
        root = y;
    } else if (x == x->parent().pointer()->right()) {
        x->parent().pointer()->right() = y;
    } else {
        x->parent().pointer()->left() = y;
    }
    y->right() = x;
    x->parent() = y;
}
