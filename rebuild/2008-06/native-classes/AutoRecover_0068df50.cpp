// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: red-black tree left rotate (MSVC std::_Tree::_Lrotate); node layout left,parent,right,color,isnil
struct TreeNode {
    TreeNode* left;
    TreeNode* parent;
    TreeNode* right;
    char color;
    char isnil;
};

struct TreeHead {
    int pad[6];
    TreeNode* head; // +0x18
};

extern "C" void __fastcall fn_0068df50(TreeHead* self, int unusedEdx, TreeNode* x)
{
    TreeNode* y = x->right;
    x->right = y->left;
    if (!y->left->isnil)
        y->left->parent = x;
    y->parent = x->parent;
    if (x == self->head->parent)
        self->head->parent = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}
