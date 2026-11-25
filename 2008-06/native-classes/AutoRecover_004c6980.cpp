// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: boost::multi_index::detail::ordered_index_node_impl::link with compressed parent/color word.
struct Local_004c6980_Node;

struct Local_004c6980_ParentRef {
    unsigned int* r;
    Local_004c6980_ParentRef(unsigned int* r_) : r(r_) {}
    operator Local_004c6980_Node*() const {
        return (Local_004c6980_Node*)(*r & ~1u);
    }
    Local_004c6980_ParentRef& operator=(Local_004c6980_Node* p) {
        *r = (unsigned int)p | (*r & 1u);
        return *this;
    }
};

struct Local_004c6980_Node {
    unsigned int parentcolor_;
    Local_004c6980_Node* left_;
    Local_004c6980_Node* right_;

    Local_004c6980_ParentRef parent() { return Local_004c6980_ParentRef(&parentcolor_); }
    Local_004c6980_Node*& left() { return left_; }
    Local_004c6980_Node*& right() { return right_; }
};

extern "C" void fn_004c6870(Local_004c6980_Node* x, Local_004c6980_ParentRef root);

extern "C" void fn_004c6980(Local_004c6980_Node* x, int side, Local_004c6980_Node* position, Local_004c6980_Node* header)
{
    if (side == 0) {
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
