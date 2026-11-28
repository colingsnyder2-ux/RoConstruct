// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were available, so the object is accessed through raw offsets.
// INFERRED: this is the constructor of Reflection::EnumDesc<DebugSettings::ErrorReporting>.
// INFERRED: the exception-unwind states (the fs:[0] frame) are not reproduced with explicit destructors.

extern "C" int fn_006a0920(int a1);

// EnumDescriptor::EnumDescriptor(const char* name, const type_info& ti)
extern "C" void* __fastcall fn_0056c590(void* self, int unusedEdx, const char* name, const void* ti);

// std::_Tree constructor (comparator and allocator by reference)
extern "C" void* __fastcall fn_00446110(void* self, int unusedEdx, void* a, void* b);

// EnumDesc<ErrorReporting>::addPair(value, name)
extern "C" void __fastcall fn_0064d530(void* self, int unusedEdx, int value, const char* name);

extern "C" char g_00945270[];  // INFERRED: typeid(DebugSettings::ErrorReporting)
extern "C" char g_0082e2f0[];  // INFERRED: EnumDesc vftable
extern "C" char g_0082e32c[];  // 'ErrorReporting'
extern "C" char g_0082e320[];  // 'DontReport'
extern "C" char g_0082e318[];  // 'Prompt'
extern "C" char g_0082e310[];  // 'Report'

static inline void initListHead(unsigned char* base, int off)
{
    void** member = (void**)(base + off);
    void** node = (void**)fn_006a0920(4);
    if (node)
        *node = member;
    else
        node = 0;
    member[0] = node;
    member[3] = 0;
    member[4] = 0;
    member[5] = 0;
}

extern "C" void* __fastcall fn_00564a60(void* self, int unusedEdx)
{
    unsigned char* p = (unsigned char*)self;
    char tmpA;
    char tmpB;

    fn_0056c590(self, 0, g_0082e32c, g_00945270);
    *(void**)p = (void*)g_0082e2f0;

    fn_00446110(p + 0x30, 0, &tmpB, &tmpA);
    fn_00446110(p + 0x50, 0, &tmpB, &tmpA);

    initListHead(p, 0x70);
    initListHead(p, 0x88);
    initListHead(p, 0xa0);
    initListHead(p, 0xb8);
    initListHead(p, 0xd0);

    fn_0064d530(self, 0, 0, g_0082e320);
    fn_0064d530(self, 0, 1, g_0082e318);
    fn_0064d530(self, 0, 2, g_0082e310);
    return self;
}
