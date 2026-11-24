// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no CRT header is included, so the CRT import is declared here (called via the IAT, as in the disassembly).
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: layouts reconstructed from the disassembly (std::_Tree map with checked iterators)
struct TreeNode {
    TreeNode* left;
    TreeNode* parent;
    TreeNode* right;
};

struct TreeIter {
    void* cont;       // proxy / container pointer, compared with tree[0]
    TreeNode* node;
};

struct TreeObj {
    void* proxy;      // +0x00
    int pad[5];       // +0x04..+0x17
    TreeNode* head;   // +0x18
    int size;         // +0x1c
};

extern "C" void __fastcall fn_00671160(TreeObj* self, int unusedEdx, TreeNode* n);          // _Erase
extern "C" void __fastcall fn_00409f60(TreeIter* it, int unusedEdx);                        // _Inc
extern "C" void* __fastcall fn_00670a50(TreeObj* self, int unusedEdx, TreeIter* ret,
                                        void* cont, TreeNode* node);                        // erase(it)

extern "C" TreeIter* __fastcall fn_00671830(TreeObj* self, int unusedEdx, TreeIter* ret,
                                            void* firstCont, TreeNode* firstNode,
                                            void* lastCont, TreeNode* lastNode)
{
    TreeIter first;
    first.cont = firstCont;
    first.node = firstNode;
    TreeNode* begin = self->head->left;

    if (!first.cont || first.cont != self->proxy)
        _invalid_parameter_noinfo();

    if (first.node == begin) {
        TreeNode* head = self->head;
        if (!lastCont || lastCont != self->proxy)
            _invalid_parameter_noinfo();
        if (lastNode == head) {
            fn_00671160(self, 0, self->head->parent);
            self->head->parent = self->head;
            self->size = 0;
            self->head->left = self->head;
            self->head->right = self->head;
            ret->node = self->head->left;
            ret->cont = self->proxy;
            return ret;
        }
    }

    for (;;) {
        if (!first.cont || first.cont != lastCont)
            _invalid_parameter_noinfo();
        TreeNode* n = first.node;
        if (n == lastNode)
            break;
        fn_00409f60(&first, 0);
        TreeIter tmp;
        fn_00670a50(self, 0, &tmp, first.cont, n);
    }
    ret->cont = self->proxy;
    ret->node = first.node;
    return ret;
}
