// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::map<unsigned, T> hint insert (iterator insert(const_iterator where, const value_type& v)),
// compiled with checked iterators; node layout: left +0, parent +4, right +8, key +0xc, isnil +0x19.
// INFERRED: tree layout: proxy +0, head +0x18, size +0x1c.

struct TreeNode {
    TreeNode* left;
    TreeNode* parent;
    TreeNode* right;
    unsigned key;
    unsigned pad;
    unsigned pad2;
    char color;
    char isnil;
};

struct TreeIter {
    void* proxy;
    TreeNode* node;
};

struct Tree {
    void* proxy;
    unsigned pad[5];
    TreeNode* head;
    unsigned size;
};

extern "C" int __fastcall fn_004af270(void* self, int unusedEdx, int a1, int a2);
extern "C" void __fastcall fn_004ae370(Tree* self, int unusedEdx, TreeIter* ret, int addLeft, TreeNode* where, const unsigned* val);
extern "C" void __fastcall fn_004abf40(TreeIter* self);
extern "C" void __fastcall fn_005b7250(TreeIter* self);
extern "C" bool __fastcall fn_005ecca0(TreeIter* self, int unusedEdx, TreeIter* other);
extern "C" void __cdecl _invalid_parameter_noinfo();

extern "C" TreeIter* __fastcall fn_00592350(Tree* self, int unusedEdx, TreeIter* ret,
                                            void* whereProxy, TreeNode* whereNode, const unsigned* val)
{
    if (self->size == 0) {
        fn_004ae370(self, 0, ret, 1, self->head, val);
        return ret;
    }
    if (!whereProxy || whereProxy != self->proxy)
        _invalid_parameter_noinfo();

    if (whereNode == self->head->left) {
        if (*val < whereNode->key) {
            fn_004ae370(self, 0, ret, 1, whereNode, val);
            return ret;
        }
    } else {
        if (!whereProxy || whereProxy != self->proxy)
            _invalid_parameter_noinfo();
        if (whereNode == self->head) {
            TreeNode* last = self->head->right;
            if (last->key < *val) {
                fn_004ae370(self, 0, ret, 0, last, val);
                return ret;
            }
        } else if (*val < whereNode->key) {
            TreeIter prev = { whereProxy, whereNode };
            fn_004abf40(&prev);
            if (prev.node->key < *val) {
                if (prev.node->right->isnil)
                    fn_004ae370(self, 0, ret, 0, prev.node, val);
                else
                    fn_004ae370(self, 0, ret, 1, whereNode, val);
                return ret;
            }
        } else if (whereNode->key < *val) {
            TreeIter next = { whereProxy, whereNode };
            TreeIter endIt = { self->proxy, self->head };
            fn_005b7250(&next);
            if (fn_005ecca0(&next, 0, &endIt) || *val < next.node->key) {
                if (whereNode->right->isnil)
                    fn_004ae370(self, 0, ret, 0, whereNode, val);
                else
                    fn_004ae370(self, 0, ret, 1, next.node, val);
                return ret;
            }
        }
    }

    TreeIter tmp;
    TreeIter* r = (TreeIter*)(long)fn_004af270(self, 0, (int)&tmp, (int)val);
    ret->proxy = r->proxy;
    ret->node = r->node;
    return ret;
}
