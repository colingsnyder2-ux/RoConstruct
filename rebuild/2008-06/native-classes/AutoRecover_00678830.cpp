// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: red-black tree node layout of a std::map<std::string, T> (MSVC 2008 release).
struct MapNode {
    MapNode*    left;      // +0x00
    MapNode*    parent;    // +0x04
    MapNode*    right;     // +0x08
    std::string key;       // +0x0c
    char        pad[0x7d - 0x0c - sizeof(std::string)];
    char        isnil;     // +0x7d
};

// INFERRED: owner class holds the map's head node pointer at +0x18
struct MapOwner {
    char     pad[0x18];
    MapNode* head;
};

// lower_bound on a string-keyed map; returns head node if not found
extern "C" MapNode* __fastcall fn_00678830(MapOwner* self, int unusedEdx, const std::string& key)
{
    MapNode* result = self->head;
    MapNode* node = result->parent;
    while (!node->isnil) {
        if (node->key < key) {
            node = node->right;
        } else {
            result = node;
            node = node->left;
        }
    }
    return result;
}
