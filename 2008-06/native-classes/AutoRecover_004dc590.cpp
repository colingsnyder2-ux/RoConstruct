// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: std::map<Key,...> lower_bound over an MSVC red-black tree; layout from the disassembly.
struct Key {
    float x, y, z;
    unsigned int a;
    int b;
};

struct TreeNode {
    TreeNode* left;
    TreeNode* parent;
    TreeNode* right;
    Key key;
    char pad[0x35 - 0x24];
    char isnil;
};

struct Tree {
    char pad[0x18];
    TreeNode* head;
};

static inline bool nodeLess(const Key& n, const Key& k)
{
    if (n.x < k.x) return true;
    if (k.x < n.x) return false;
    if (n.y < k.y) return true;
    if (k.y < n.y) return false;
    if (n.z < k.z) return true;
    if (k.z < n.z) return false;
    if (n.a < k.a) return true;
    if (n.a > k.a) return false;
    return n.b < k.b;
}

extern "C" TreeNode* __fastcall fn_004dc590(Tree* self, int unusedEdx, const Key* key)
{
    TreeNode* result = self->head;
    TreeNode* node = result->parent;
    while (!node->isnil) {
        if (nodeLess(node->key, *key)) {
            node = node->right;
        } else {
            result = node;
            node = node->left;
        }
    }
    return result;
}
