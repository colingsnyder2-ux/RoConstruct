// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: red-black tree node (std::map-style); _Left is the first field, _Isnil is at offset 0x39.
struct TreeNode {
    TreeNode* left;
    TreeNode* parent;
    TreeNode* right;
    char pad[0x39 - 3 * sizeof(TreeNode*)];
    char isNil;
};

// INFERRED: walks left until the left child is the sentinel; returns the leftmost node (tree minimum).
extern "C" TreeNode* fn_0068d120(TreeNode* node)
{
    TreeNode* next = node->left;
    while (!next->isNil) {
        node = next;
        next = node->left;
    }
    return node;
}
