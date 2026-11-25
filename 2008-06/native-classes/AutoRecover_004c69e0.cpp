// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: boost::multi_index::detail::ordered_index_node_impl::rebalance_for_erase
// with compressed parent/colour word (low bit = colour: 0=red, 1=black).
enum Local_004c69e0_Color { red = 0, black = 1 };

struct Local_004c69e0_Node;

struct Local_004c69e0_ColorRef {
    unsigned int* r;
    operator Local_004c69e0_Color() const {
        return (Local_004c69e0_Color)(*r & 1u);
    }
    Local_004c69e0_ColorRef& operator=(Local_004c69e0_Color c) {
        *r &= ~1u;
        *r |= (unsigned int)c;
        return *this;
    }
    Local_004c69e0_ColorRef& operator=(const Local_004c69e0_ColorRef& x) {
        return operator=((Local_004c69e0_Color)x);
    }
};

struct Local_004c69e0_ParentRef {
    unsigned int* r;
    operator Local_004c69e0_Node*() const {
        return (Local_004c69e0_Node*)(*r & ~1u);
    }
    Local_004c69e0_ParentRef& operator=(Local_004c69e0_Node* p) {
        *r = (unsigned int)p | (*r & 1u);
        return *this;
    }
    Local_004c69e0_ParentRef& operator=(const Local_004c69e0_ParentRef& x) {
        return operator=((Local_004c69e0_Node*)x);
    }
    Local_004c69e0_Node* operator->() const {
        return (Local_004c69e0_Node*)(*r & ~1u);
    }
};

struct Local_004c69e0_Node {
    unsigned int parentcolor_;
    Local_004c69e0_Node* left_;
    Local_004c69e0_Node* right_;

    Local_004c69e0_ColorRef color() { Local_004c69e0_ColorRef c; c.r = &parentcolor_; return c; }
    Local_004c69e0_ParentRef parent() { Local_004c69e0_ParentRef p; p.r = &parentcolor_; return p; }
    Local_004c69e0_Node*& left() { return left_; }
    Local_004c69e0_Node*& right() { return right_; }
};

extern "C" void fn_004c6770(Local_004c69e0_Node* x, Local_004c69e0_ParentRef root);
extern "C" void fn_004c67f0(Local_004c69e0_Node* x, Local_004c69e0_ParentRef root);

static inline Local_004c69e0_Node* minimum(Local_004c69e0_Node* x)
{
    while (x->left()) x = x->left();
    return x;
}

static inline Local_004c69e0_Node* maximum(Local_004c69e0_Node* x)
{
    while (x->right()) x = x->right();
    return x;
}

extern "C" Local_004c69e0_Node* fn_004c69e0(
    Local_004c69e0_Node* z, Local_004c69e0_ParentRef root,
    Local_004c69e0_Node*& leftmost, Local_004c69e0_Node*& rightmost)
{
    Local_004c69e0_Node* y = z;
    Local_004c69e0_Node* x = 0;
    Local_004c69e0_Node* x_parent = 0;

    if (y->left() == 0) {
        x = y->right();
    } else {
        if (y->right() == 0) {
            x = y->left();
        } else {
            y = y->right();
            while (y->left()) y = y->left();
            x = y->right();
        }
    }
    if (y != z) {
        z->left()->parent() = y;
        y->left() = z->left();
        if (y != z->right()) {
            x_parent = y->parent();
            if (x) x->parent() = y->parent();
            y->parent()->left() = x;
            y->right() = z->right();
            z->right()->parent() = y;
        } else {
            x_parent = y;
        }
        if (root == z)                      root = y;
        else if (z->parent()->left() == z)  z->parent()->left() = y;
        else                                z->parent()->right() = y;
        y->parent() = z->parent();
        Local_004c69e0_Color c = y->color();
        y->color() = z->color();
        z->color() = c;
        y = z;
    } else {
        x_parent = y->parent();
        if (x) x->parent() = y->parent();
        if (root == z) {
            root = x;
        } else {
            if (z->parent()->left() == z) z->parent()->left() = x;
            else                          z->parent()->right() = x;
        }
        if (leftmost == z) {
            if (z->right() == 0) {
                leftmost = z->parent();
            } else {
                leftmost = minimum(x);
            }
        }
        if (rightmost == z) {
            if (z->left() == 0) {
                rightmost = z->parent();
            } else {
                rightmost = maximum(x);
            }
        }
    }
    if (y->color() != red) {
        while (x != root && (x == 0 || x->color() == black)) {
            if (x == x_parent->left()) {
                Local_004c69e0_Node* w = x_parent->right();
                if (w->color() == red) {
                    w->color() = black;
                    x_parent->color() = red;
                    fn_004c6770(x_parent, root);
                    w = x_parent->right();
                }
                if ((w->left() == 0 || w->left()->color() == black) &&
                    (w->right() == 0 || w->right()->color() == black)) {
                    w->color() = red;
                    x = x_parent;
                    x_parent = x_parent->parent();
                } else {
                    if (w->right() == 0 || w->right()->color() == black) {
                        if (w->left()) w->left()->color() = black;
                        w->color() = red;
                        fn_004c67f0(w, root);
                        w = x_parent->right();
                    }
                    w->color() = x_parent->color();
                    x_parent->color() = black;
                    if (w->right()) w->right()->color() = black;
                    fn_004c6770(x_parent, root);
                    break;
                }
            } else {
                Local_004c69e0_Node* w = x_parent->left();
                if (w->color() == red) {
                    w->color() = black;
                    x_parent->color() = red;
                    fn_004c67f0(x_parent, root);
                    w = x_parent->left();
                }
                if ((w->right() == 0 || w->right()->color() == black) &&
                    (w->left() == 0 || w->left()->color() == black)) {
                    w->color() = red;
                    x = x_parent;
                    x_parent = x_parent->parent();
                } else {
                    if (w->left() == 0 || w->left()->color() == black) {
                        if (w->right()) w->right()->color() = black;
                        w->color() = red;
                        fn_004c6770(w, root);
                        w = x_parent->left();
                    }
                    w->color() = x_parent->color();
                    x_parent->color() = black;
                    if (w->left()) w->left()->color() = black;
                    fn_004c67f0(x_parent, root);
                    break;
                }
            }
        }
        if (x) x->color() = black;
    }
    return y;
}
