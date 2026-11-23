// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::map<K,V>::insert(hint, value) in debug-iterator form (_HAS_ITERATOR_DEBUGGING-style
// proxy check). Layout from the disassembly: +0 proxy, +8 comparator, +0x18 head node, +0x1c size.
// _invalid_parameter_noinfo checks are omitted; the debug-iterator proxy checks are not reproduced.

struct TreeNode {
    TreeNode* left;
    TreeNode* parent;
    TreeNode* right;
    int key[1];          // key lives at +0xc
    char pad[0x29 - 0x10];
    char isnil;          // +0x29
};

struct TreeIter {
    void* proxy;
    TreeNode* node;
};

struct TreeMap {
    void* proxy;
    int unused4;
    char cmp[0x10];      // comparator at +8
    TreeNode* head;      // +0x18
    int size;            // +0x1c
};

extern "C" int __fastcall fn_004e7cd0(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
extern "C" int __fastcall fn_004e61a0(void* self, int unusedEdx, int a1, int a2);
extern "C" TreeIter* __fastcall fn_004e8d50(void* self, int unusedEdx, int a1, int a2);
extern "C" void __fastcall fn_004386e0(TreeIter* it);   // _Dec
extern "C" void __fastcall fn_00438770(TreeIter* it);   // _Inc
extern "C" bool __fastcall fn_005ecca0(TreeIter* a, int unusedEdx, TreeIter* b);   // operator==

extern "C" TreeIter* __fastcall fn_004e9a30(TreeMap* self, int unusedEdx,
                                            TreeIter* out, void* hintProxy,
                                            TreeNode* hintNode, int key)
{
    void* cmp = self->cmp;
    TreeNode* head = self->head;

    if (self->size == 0) {
        fn_004e7cd0(self, 0, (int)out, 1, (int)head, key);
        return out;
    }

    if (hintNode == head->left) {
        if (fn_004e61a0(cmp, 0, key, (int)&hintNode->key[0])) {
            fn_004e7cd0(self, 0, (int)out, 1, (int)hintNode, key);
            return out;
        }
    } else if (hintNode == head) {
        TreeNode* last = head->right;
        if (fn_004e61a0(cmp, 0, (int)&last->key[0], key)) {
            fn_004e7cd0(self, 0, (int)out, 0, (int)last, key);
            return out;
        }
    } else {
        TreeIter it;
        it.proxy = hintProxy;
        it.node = hintNode;
        if (fn_004e61a0(cmp, 0, key, (int)&hintNode->key[0])) {
            fn_004386e0(&it);
            TreeNode* prev = it.node;
            if (fn_004e61a0(cmp, 0, (int)&prev->key[0], key)) {
                if (prev->right->isnil)
                    fn_004e7cd0(self, 0, (int)out, 0, (int)prev, key);
                else
                    fn_004e7cd0(self, 0, (int)out, 1, (int)hintNode, key);
                return out;
            }
        }
        if (fn_004e61a0(cmp, 0, (int)&hintNode->key[0], key)) {
            TreeIter end;
            end.proxy = self->proxy;
            end.node = self->head;
            it.proxy = hintProxy;
            it.node = hintNode;
            fn_00438770(&it);
            TreeNode* next = it.node;
            if (fn_005ecca0(&it, 0, &end) ||
                fn_004e61a0(cmp, 0, key, (int)&next->key[0])) {
                if (hintNode->right->isnil)
                    fn_004e7cd0(self, 0, (int)out, 0, (int)hintNode, key);
                else
                    fn_004e7cd0(self, 0, (int)out, 1, (int)next, key);
                return out;
            }
        }
    }

    TreeIter tmp;
    TreeIter* r = fn_004e8d50(self, 0, (int)&tmp, key);
    out->proxy = r->proxy;
    out->node = r->node;
    return out;
}
