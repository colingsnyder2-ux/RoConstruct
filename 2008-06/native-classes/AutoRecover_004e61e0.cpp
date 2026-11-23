// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout from disassembly only: MSVC std::map-style red-black tree, lower_bound with (int at +0x18, then address) ordering.
struct TreeNode {
    TreeNode* left;
    TreeNode* parent;
    TreeNode* right;
    char value[12];
    int key;
    char pad[5];
    char isnil;
};
struct TreeHead { int unused; TreeNode* head; };
struct TreeKey { char pad[0xc]; int key; };
struct TreeOwner { char pad[0x18]; TreeHead* tree; };

extern "C" TreeNode* __fastcall fn_004e61e0(TreeOwner* self, int unusedEdx, TreeKey* arg)
{
    TreeNode* result = (TreeNode*)self->tree;
    TreeNode* node = result->parent;
    while (!node->isnil) {
        if (node->key < arg->key ||
            (node->key == arg->key && (void*)node->value < (void*)arg)) {
            node = node->right;
        } else {
            result = node;
            node = node->left;
        }
    }
    return result;
}
