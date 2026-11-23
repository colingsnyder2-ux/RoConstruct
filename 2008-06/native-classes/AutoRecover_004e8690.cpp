// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout from disassembly only; pair<iterator,iterator> of two node pointers, returned via out pointer.
struct Node4e8690 {
    int pad[3];
    int key;     // +0x0c
    int pad2[2];
    int key2;    // +0x18
};

struct Self4e8690 {
    Node4e8690* first;   // +0x00
    int pad[5];
    Node4e8690* last;    // +0x18
};

struct Pair4e8690 {
    Node4e8690* a;
    Node4e8690* b;
};

extern "C" TreeNode* __fastcall fn_004e61e0(TreeOwner* self, int unusedEdx, TreeKey* arg);

extern "C" Pair4e8690* __fastcall fn_004e8690(Self4e8690* self, int unusedEdx, Pair4e8690* out, Node4e8690* key)
{
    Node4e8690* found = (Node4e8690*)fn_004e61e0((int)key);
    Pair4e8690 r;
    if (found != self->last &&
        !(key->key < found->key2 ||
          (key->key == found->key2 && (unsigned)key < (unsigned)((char*)found + 0xc)))) {
        r.a = found;
        r.b = found;
    } else {
        r.a = self->first;
        r.b = self->last;
    }
    *out = r;
    return out;
}
