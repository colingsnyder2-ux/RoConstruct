// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: boost::multi_index::detail::ordered_index_node_impl::rebalance
// with compressed parent/colour word (low bit = colour: 0=red, 1=black).
enum Local_004c6870_Color { red = 0, black = 1 };

struct Local_004c6870_Node;

struct Local_004c6870_ColorRef {
    unsigned int* r;
    operator Local_004c6870_Color() const {
        return (Local_004c6870_Color)(*r & 1u);
    }
    Local_004c6870_ColorRef& operator=(Local_004c6870_Color c) {
        *r &= ~1u;
        *r |= (unsigned int)c;
        return *this;
    }
    Local_004c6870_ColorRef& operator=(const Local_004c6870_ColorRef& x) {
        return operator=((Local_004c6870_Color)x);
    }
};

struct Local_004c6870_ParentRef {
    unsigned int* r;
    operator Local_004c6870_Node*() const {
        return (Local_004c6870_Node*)(*r & ~1u);
    }
    Local_004c6870_ParentRef& operator=(Local_004c6870_Node* p) {
        *r = (unsigned int)p | (*r & 1u);
        return *this;
    }
    Local_004c6870_ParentRef& operator=(const Local_004c6870_ParentRef& x) {
        return operator=((Local_004c6870_Node*)x);
    }
    Local_004c6870_Node* operator->() const {
        return (Local_004c6870_Node*)(*r & ~1u);
    }
};

struct Local_004c6870_Node {
    unsigned int parentcolor_;
    Local_004c6870_Node* left_;
    Local_004c6870_Node* right_;

    Local_004c6870_ColorRef color() { Local_004c6870_ColorRef c; c.r = &parentcolor_; return c; }
    Local_004c6870_ParentRef parent() { Local_004c6870_ParentRef p; p.r = &parentcolor_; return p; }
    Local_004c6870_Node*& left() { return left_; }
    Local_004c6870_Node*& right() { return right_; }
};

extern "C" void fn_004c6770(Local_004c6870_Node* x, Local_004c6870_ParentRef root);
extern "C" void fn_004c67f0(Local_004c6870_Node* x, Local_004c6870_ParentRef root);

extern "C" void fn_004c6870(Local_004c6870_Node* x, Local_004c6870_ParentRef root)
{
    x->color() = red;
    while (x != root && x->parent()->color() == red) {
        if (x->parent() == x->parent()->parent()->left()) {
            Local_004c6870_Node* y = x->parent()->parent()->right();
            if (y && y->color() == red) {
                x->parent()->color() = black;
                y->color() = black;
                x->parent()->parent()->color() = red;
                x = x->parent()->parent();
            } else {
                if (x == x->parent()->right()) {
                    x = x->parent();
                    fn_004c6770(x, root);
                }
                x->parent()->color() = black;
                x->parent()->parent()->color() = red;
                fn_004c67f0(x->parent()->parent(), root);
            }
        } else {
            Local_004c6870_Node* y = x->parent()->parent()->left();
            if (y && y->color() == red) {
                x->parent()->color() = black;
                y->color() = black;
                x->parent()->parent()->color() = red;
                x = x->parent()->parent();
            } else {
                if (x == x->parent()->left()) {
                    x = x->parent();
                    fn_004c67f0(x, root);
                }
                x->parent()->color() = black;
                x->parent()->parent()->color() = red;
                fn_004c6770(x->parent()->parent(), root);
            }
        }
    }
    root->color() = black;
}
