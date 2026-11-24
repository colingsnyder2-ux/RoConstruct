// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::map-style lower_bound over an RB tree; layouts from the disassembly only.
struct Fn4e6220Key {
    char pad[0xc];
    int a;            // +0xc, signed compare
    unsigned int b;   // +0x10, unsigned compare
};
struct Fn4e6220Node {
    Fn4e6220Node* left;
    Fn4e6220Node* parent;
    Fn4e6220Node* right;
    Fn4e6220Key key;  // +0xc, 0x14 bytes
    char pad[0x29 - 0x20];
    char isNil;       // +0x29
};
struct Fn4e6220Tree {
    int pad;
    Fn4e6220Node* root; // +4
};
struct Fn4e6220Self {
    char pad[0x18];
    Fn4e6220Tree* tree;
};

extern "C" Fn4e6220Node* __fastcall fn_004e6220(Fn4e6220Self* self, int unusedEdx, Fn4e6220Key* k)
{
    Fn4e6220Node* result = (Fn4e6220Node*)self->tree;
    Fn4e6220Node* n = self->tree->root;
    while (!n->isNil) {
        const Fn4e6220Key* nk = &n->key;
        bool less;
        if (nk->b != k->b)
            less = nk->b < k->b;
        else if (nk->a != k->a)
            less = nk->a < k->a;
        else
            less = (const void*)nk < (const void*)k;
        if (less) {
            n = n->right;
        } else {
            result = n;
            n = n->left;
        }
    }
    return result;
}
