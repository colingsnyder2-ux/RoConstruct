// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

struct TreeNode {
    TreeNode* left;
    TreeNode* parent;
    TreeNode* right;
    char color;
    char isnil;
};

extern "C" int __fastcall fn_0068fff0(void* self, int unusedEdx, int a1);

// INFERRED: std::_Tree::_Erase style recursive node destruction
extern "C" int __fastcall fn_0068fff0(void* self, int unusedEdx, int a1)
{
    TreeNode* node = (TreeNode*)a1;
    while (!node->isnil) {
        fn_0068fff0(self, 0, (int)node->right);
        TreeNode* next = node->left;
        ::operator delete(node);
        node = next;
    }
    return 0;
}
