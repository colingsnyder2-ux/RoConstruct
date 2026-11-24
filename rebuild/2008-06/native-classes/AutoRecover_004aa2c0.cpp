// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was provided, so this is a self-contained layout
// built from the offsets used in the disassembly.
struct PhysicsReceiveMethodEnumDesc;

extern "C" int fn_006a0920(int a1);
extern "C" void* g_008240c4[];  // vtable
extern "C" char g_0093a918;     // type_info for the enum type

// EnumDescriptor::EnumDescriptor(const char*, const type_info&)
extern "C" void* __fastcall fn_0056c590(void* self, int unusedEdx, const char* name, const void* typeInfo);
// std::map tree constructors
extern "C" void* __fastcall fn_00446110(void* self, int unusedEdx, void* a, void* b);
// EnumDesc::addPair(value, name)
extern "C" void __fastcall fn_0064d530(void* self, int unusedEdx, int value, const char* name);

// INFERRED: each of the five containers at 0x70..0xd0 is a 0x18-byte list/map
// whose sentinel node is allocated with a 4-byte operator new.
static inline void initContainer(int* c)
{
    int* node = (int*)fn_006a0920(4);
    if (node)
        *node = (int)c;
    else
        node = 0;
    c[0] = (int)node;
    c[3] = 0;
    c[4] = 0;
    c[5] = 0;
}

extern "C" PhysicsReceiveMethodEnumDesc* __fastcall fn_004aa2c0(PhysicsReceiveMethodEnumDesc* self, int unusedEdx)
{
    char* base = (char*)self;
    char tmpA;
    char tmpB;

    fn_0056c590(self, 0, "PhysicsReceiveMethod", &g_0093a918);
    *(void***)base = g_008240c4;

    fn_00446110(base + 0x30, 0, &tmpA, &tmpB);
    fn_00446110(base + 0x50, 0, &tmpA, &tmpB);

    initContainer((int*)(base + 0x70));
    initContainer((int*)(base + 0x88));
    initContainer((int*)(base + 0xa0));
    initContainer((int*)(base + 0xb8));
    initContainer((int*)(base + 0xd0));

    fn_0064d530(self, 0, 0, "Direct");
    fn_0064d530(self, 0, 1, "Interpolation");
    return self;
}
