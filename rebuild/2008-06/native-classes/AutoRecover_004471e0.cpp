// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were provided, so the layout is reconstructed from the disassembly offsets.
// Unwind state numbers and exact byte output have not been checked against the original.

struct type_info;

struct GraphicsModeDesc {
    void* vtbl;          // 0x00 (set after the EnumDescriptor base ctor)
    char  base[0x2c];    // EnumDescriptor base remainder
    char  mapA[0x20];    // 0x30 std::map-like tree
    char  mapB[0x20];    // 0x50 std::map-like tree
    char  lists[5][0x18];// 0x70, 0x88, 0xa0, 0xb8, 0xd0
};

extern "C" int fn_006a0920(int a1);
extern "C" void __fastcall fn_0056c590(void* self, int unusedEdx, const char* name, const type_info* ti);
extern "C" void __fastcall fn_00446110(void* self, int unusedEdx, char* a, char* b);
extern "C" void __fastcall fn_0064d530(void* self, int unusedEdx, int value, const char* name);

extern "C" char g_00815ed4[];     // vtable
extern "C" const type_info g_00931434; // INFERRED: typeid(GraphicsMode)

// INFERRED: 5 small list-like members, each with a 4-byte sentinel node pointing back at the owner
static inline void initList(char* p)
{
    int* node = (int*)fn_006a0920(4);
    int* head;
    if (node != 0) {
        *node = (int)p;
        head = node;
    } else {
        head = 0;
    }
    int* L = (int*)p;
    L[0]  = (int)head;
    L[3]  = 0;
    L[4]  = 0;
    L[5]  = 0;
}

extern "C" GraphicsModeDesc* __fastcall fn_004471e0(GraphicsModeDesc* self, int unusedEdx)
{
    char t1, t2;
    fn_0056c590(self, 0, "GraphicsMode", &g_00931434);
    self->vtbl = g_00815ed4;
    fn_00446110(self->mapA, 0, &t2, &t1);
    fn_00446110(self->mapB, 0, &t2, &t1);
    for (int i = 0; i < 5; ++i)
        initList(self->lists[i]);
    fn_0064d530(self, 0, 1, "Automatic");
    fn_0064d530(self, 0, 2, "OpenGL stable");
    fn_0064d530(self, 0, 3, "Direct3D experimental");
    fn_0064d530(self, 0, 4, "OpenGL experimental");
    fn_0064d530(self, 0, 5, "No Graphics");
    return self;
}
