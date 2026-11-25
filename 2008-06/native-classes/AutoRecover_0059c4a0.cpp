// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were provided, so every layout and callee below is reconstructed
// from the disassembly. Exception-unwind state (the fs:[0] frame) is not reproduced.
// INFERRED: the five 0x18-byte members at +0x70..+0xd0 are modelled as a head-node container.

struct HeadNode { void* owner; };

struct NodeContainer {
    HeadNode* head;   // +0x00
    int       pad[2]; // +0x04, +0x08 left untouched
    int       a;      // +0x0c
    int       b;      // +0x10
    int       c;      // +0x14
};

struct FormFactorEnumDesc {
    const void*   vtable;      // +0x00
    char          base[0x2c];  // EnumDescriptor base data up to +0x30
    char          mapA[0x20];  // +0x30
    char          mapB[0x20];  // +0x50
    NodeContainer c0;          // +0x70
    NodeContainer c1;          // +0x88
    NodeContainer c2;          // +0xa0
    NodeContainer c3;          // +0xb8
    NodeContainer c4;          // +0xd0
};

extern "C" int g_0094ab60;     // type_info for the enum type
extern "C" char g_00832db8[];  // INFERRED: vtable of the FormFactor enum descriptor
extern "C" void __fastcall fn_0056c590(void* self, int unusedEdx, const char* name, const void* ti);
extern "C" void __fastcall fn_00446110(void* self, int unusedEdx, void* a, void* b);
extern "C" int fn_006a0920(int a1);
extern "C" void __fastcall fn_0064d530(void* self, int unusedEdx, int value, const char* name);
extern "C" const void* fn_00553f90(const char* name, int n);
extern "C" int* __fastcall fn_005644a0(void* self, int unusedEdx, const void** key);

static inline void initContainer(NodeContainer* c)
{
    HeadNode* n = (HeadNode*)fn_006a0920(4);
    if (n)
        n->owner = c;
    else
        n = 0;
    c->head = n;
    c->a = 0;
    c->b = 0;
    c->c = 0;
}

extern "C" FormFactorEnumDesc* __fastcall fn_0059c4a0(FormFactorEnumDesc* self, int unusedEdx)
{
    char t1, t2;
    fn_0056c590(self, 0, "FormFactor", &g_0094ab60);
    self->vtable = g_00832db8;
    fn_00446110(self->mapA, 0, &t2, &t1);
    fn_00446110(self->mapB, 0, &t2, &t1);
    initContainer(&self->c0);
    initContainer(&self->c1);
    initContainer(&self->c2);
    initContainer(&self->c3);
    initContainer(&self->c4);
    fn_0064d530(self, 0, 0, "Symmetric");
    fn_0064d530(self, 0, 1, "Brick");
    fn_0064d530(self, 0, 2, "Plate");
    const void* key = fn_00553f90("Block", -1);
    *fn_005644a0(self->mapB, 0, &key) = 1;
    return self;
}
