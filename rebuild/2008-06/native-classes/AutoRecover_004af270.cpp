// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::map<SoundType, shared_ptr<SoundChannel>>::insert (unique-key _Tree::insert, MSVC 2008 layout)

struct TreeNode {
    TreeNode* left;
    TreeNode* parent;
    TreeNode* right;
    unsigned key;
    char pad[9];
    char color;
    char isNil;
};

struct TreeIter {
    int proxy;
    TreeNode* node;
};

struct InsertResult {
    int proxy;
    TreeNode* node;
    bool inserted;
};

struct SoundTree {
    int proxy;
    int pad[5];
    TreeNode* head;
};

extern "C" TreeIter* __fastcall fn_004ae370(SoundTree* self, int unusedEdx, TreeIter* where, bool addLeft, TreeNode* y, const unsigned* val);
extern "C" void fn_004abf40(TreeIter* it);

extern "C" InsertResult* __fastcall fn_004af270(SoundTree* self, int unusedEdx, InsertResult* out, const unsigned* val)
{
    TreeNode* y = self->head;
    TreeNode* x = y->parent;
    bool addLeft = true;
    while (!x->isNil) {
        y = x;
        addLeft = *val < x->key;
        x = addLeft ? x->left : x->right;
    }
    TreeIter where;
    where.proxy = self->proxy;
    where.node = y;
    if (addLeft) {
        if (y == self->head->left) {
            TreeIter* r = fn_004ae370(self, 0, &where, true, y, val);
            out->node = r->node;
            out->inserted = true;
            out->proxy = r->proxy;
            return out;
        }
        fn_004abf40(&where);
    }
    if (where.node->key < *val) {
        TreeIter* r = fn_004ae370(self, 0, &where, addLeft, y, val);
        out->node = r->node;
        out->inserted = true;
        out->proxy = r->proxy;
        return out;
    }
    out->node = where.node;
    out->inserted = false;
    out->proxy = where.proxy;
    return out;
}
