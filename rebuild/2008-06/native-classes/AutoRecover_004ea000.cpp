// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>

// INFERRED: this is an inlined std::map<Key, RCP<Texture>>::operator[] on a key of 0x18 bytes.
// The layouts below are stand-ins for headers I did not have.
struct TexKey {
    float x, y, z;
    int   w;
    float u, v;
};

struct RcObject {
    void** vtbl;
    volatile LONG refCount; // +4
};

struct TexPair {
    TexKey   key;
    RcObject* tex; // ReferenceCountedPointer<Texture>
};

struct TexNode {
    char   hdr[0xc];
    TexKey key;     // +0xc
    RcObject* tex;  // +0x24
};

struct TexMap {
    void*    head;      // +0
    char     pad[0x14];
    TexNode* endNode;   // +0x18
};

struct IterResult {
    void*    cont;
    TexNode* node;
};

extern "C" Fn4e6220Node* __fastcall fn_004e6220(Fn4e6220Self* self, int unusedEdx, Fn4e6220Key* k);
extern "C" int __fastcall fn_004e9a30(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
extern "C" void __fastcall fn_00598fa0(RcObject** self, int unusedEdx, void* p);
extern "C" void __fastcall fn_0045ad90(RcObject* self, int unusedEdx);

extern "C" RcObject** __fastcall fn_004ea000(TexMap* self, int unusedEdx, TexKey* key)
{
    TexNode* node = (TexNode*)fn_004e6220((int)key);
    TexNode* endNode = self->endNode;
    void* cont = self->head;

    bool doInsert = false;
    if (node == endNode) {
        doInsert = true;
    } else {
        ULONG_PTR a = (ULONG_PTR)&key->u;
        ULONG_PTR b = (ULONG_PTR)&node->key.u;
        if (a < b) {
            doInsert = true;
        } else if (a > b) {
            doInsert = false;
        } else if (key->w < node->key.w) {
            doInsert = true;
        } else if (key->w > node->key.w) {
            doInsert = false;
        } else {
            doInsert = ((ULONG_PTR)key < (ULONG_PTR)&node->key);
        }
    }

    if (doInsert) {
        TexPair pr;
        pr.key.x = key->x;
        pr.key.y = key->y;
        pr.key.w = key->w;
        pr.key.z = key->z;
        pr.key.u = key->u;
        pr.key.v = key->v;
        pr.tex = 0;
        fn_00598fa0(&pr.tex, 0, 0);

        IterResult res;
        IterResult* r = (IterResult*)(LONG_PTR)fn_004e9a30(self, 0, (int)&res, (int)cont, (int)node, (int)&pr);
        cont = r->cont;
        node = r->node;

        RcObject* t = pr.tex;
        if (t) {
            if (InterlockedDecrement(&t->refCount) == 0) {
                fn_0045ad90(t, 0);
                typedef void (__thiscall *DtorFn)(RcObject*, int);
                ((DtorFn)t->vtbl[0])(t, 1);
            }
        }
    }
    (void)cont;
    return &node->tex;
}
