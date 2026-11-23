// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace G3D {
class System {
public:
    static void free(void* p);
    static void alignedFree(void* p);
};
}

struct PoolNode {
    char pad0[8];
    void* vtbl;          // INFERRED: sub-object at +8 gets vtable reset before its dtor-like helper
    char pad1[0x10];
    PoolNode* next;      // +0x18
};

struct PoolArray {
    int unk0;
    int field4;
    PoolNode** data;     // +8
    int num;             // +0xc
};

// INFERRED: vtable of the node sub-object (original address 0x826c14)
extern "C" char g_00826c14[];

extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);

extern "C" void __fastcall fn_004d8f80(PoolArray* self, int unusedEdx)
{
    for (int i = 0; i < self->num; ++i) {
        PoolNode* n = self->data[i];
        while (n) {
            PoolNode* next = n->next;
            n->vtbl = g_00826c14;
            fn_004d7e30(&n->vtbl, 0);
            G3D::System::free(n);
            n = next;
        }
    }
    G3D::System::alignedFree(self->data);
    self->data = 0;
    self->num = 0;
    self->field4 = 0;
}
