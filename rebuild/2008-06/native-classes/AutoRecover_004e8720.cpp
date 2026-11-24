// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this looks like a std::map::find over a red-black tree with a
// checked iterator that is a (proxy, node) pair, returned through an out pointer.
struct FindKey {
    char pad[0xc];
    int lo;            // +0x0c, compared signed
    unsigned int hi;   // +0x10, compared unsigned first
};

struct FindNode {
    FindNode* left;
    FindNode* parent;
    FindNode* right;
    FindKey key;       // +0x0c
};

struct FindIter {
    void* proxy;
    FindNode* node;
};

struct FindTree {
    void* proxy;       // +0x00
    char pad[0x14];
    FindNode* head;    // +0x18
};

extern "C" Fn4e6220Node* __fastcall fn_004e6220(Fn4e6220Self* self, int unusedEdx, Fn4e6220Key* k);

extern "C" void __fastcall fn_004e8720(FindTree* self, int unusedEdx, FindIter* out, FindKey* key)
{
    FindNode* node = (FindNode*)fn_004e6220((int)key);
    FindNode* head = self->head;
    FindIter result;

    bool useEnd = false;
    if (node == head) {
        useEnd = true;
    } else {
        const FindKey* nk = &node->key;
        // INFERRED: inlined key "less" comparison: key < node->key
        if (key->hi < nk->hi) {
            useEnd = true;
        } else if (key->hi > nk->hi) {
            useEnd = false;
        } else if (key->lo < nk->lo) {
            useEnd = true;
        } else if (key->lo > nk->lo) {
            useEnd = false;
        } else if (key < nk) {
            useEnd = true;
        }
    }

    if (useEnd) {
        result.proxy = self->proxy;
        result.node = self->head;
    } else {
        result.proxy = self->proxy;
        result.node = node;
    }
    out->proxy = result.proxy;
    out->node = result.node;
}
