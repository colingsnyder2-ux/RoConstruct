// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: std::map/_Tree node (MSVC 2008 layout: _Left, _Parent, _Right, value..., _Isnil at 0x39).
// The function returns the rightmost node of the subtree rooted at the given node (_Tree::_Max).
struct TreeNode {
    TreeNode* left;    // +0
    TreeNode* parent;  // +4
    TreeNode* right;   // +8
    char      pad[0x39 - 12];
    char      isnil;   // +0x39
};

extern "C" TreeNode* fn_0068d100(TreeNode* node)
{
    while (!node->right->isnil)
        node = node->right;
    return node;
}
