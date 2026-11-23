// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: G3D-style array of bucket-chain heads; node = {pad[8], sub-object at +8 (vtable), ..., next at +0x18}.
namespace G3D { struct System { static void free(void* p); static void alignedFree(void* p); }; }

extern "C" char vt_00826c1c[]; // INFERRED: vtable at 0x826c1c
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);

struct ChainNode {
    int pad0[2];
    void* vptr;      // +8
    int pad1[3];
    ChainNode* next; // +0x18
};

struct ChainTable {
    int field4;
    ChainNode** data; // +8
    int size;         // +0xc
};

extern "C" void __fastcall fn_004d8ff0(ChainTable* self, int unusedEdx)
{
    for (int i = 0; i < self->size; ++i) {
        ChainNode* n = self->data[i];
        while (n) {
            ChainNode* next = n->next;
            n->vptr = vt_00826c1c;
            fn_004d7e30(&n->vptr, 0);
            G3D::System::free(n);
            n = next;
        }
    }
    G3D::System::alignedFree(self->data);
    self->data = 0;
    self->size = 0;
    self->field4 = 0;
}
