// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: boost multi_index ordered_index_node_impl style rotate_left
// with compressed parent/colour word (low bit = colour).
struct OINode;

struct OIParentRef {
    unsigned int* pc;

    OINode* pointer() const { return (OINode*)(*pc & 0xfffffffeu); }

    OIParentRef& operator=(OINode* p) {
        *pc = (unsigned int)p | (*pc & 1u);
        return *this;
    }
    OIParentRef& operator=(const OIParentRef& r) {
        // INFERRED: keep own colour bit, take other's pointer bits
        *pc = (*pc & 1u) | (*r.pc & 0xfffffffeu);
        return *this;
    }
};

struct OINode {
    unsigned int parentcolor;
    OINode* leftp;
    OINode* rightp;

    OIParentRef parent() { OIParentRef r; r.pc = &parentcolor; return r; }
    OINode*& left() { return leftp; }
    OINode*& right() { return rightp; }
};

extern "C" void fn_004c6770(OINode* x, unsigned int* rootpc)
{
    OIParentRef root;
    root.pc = rootpc;

    OINode* y = x->right();
    x->right() = y->left();
    if (y->left() != 0) {
        y->left()->parent() = x;
    }
    y->parent() = x->parent();
    if (x == root.pointer()) {
        root = y;
    } else if (x == x->parent().pointer()->left()) {
        x->parent().pointer()->left() = y;
    } else {
        x->parent().pointer()->right() = y;
    }
    y->left() = x;
    x->parent() = y;
}
