// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were available, so this is the EnumDesc<EnviromentalPhysicsThrottle>
// constructor written against raw member offsets and fn_ externs.
// It will not match the original's SEH unwind states, because no destructible members are declared.

extern "C" void* __fastcall fn_0056c590(void* self, int unusedEdx, const char* name, const void* typeInfo);
extern "C" void* __fastcall fn_00446110(void* self, int unusedEdx, void* a, void* b);
extern "C" void __fastcall fn_0064d530(void* self, int unusedEdx, int value, const char* name);
extern "C" int fn_006a0920(int a1);

extern "C" char g_009452a0[];   // type_info of the enum (INFERRED)
extern "C" char g_0082e2fc[];   // vtable (INFERRED)

static void initList(char* base)
{
    // INFERRED: empty container with a freshly allocated sentinel node
    int* head = (int*)fn_006a0920(4);
    if (head)
        *head = (int)base;
    else
        head = 0;
    *(int**)base = head;
    *(int*)(base + 0xc) = 0;
    *(int*)(base + 0x10) = 0;
    *(int*)(base + 0x14) = 0;
}

extern "C" void* __fastcall fn_00564be0(void* self, int unusedEdx)
{
    char* p = (char*)self;
    char a[4];
    char b[4];

    fn_0056c590(self, 0, "EnviromentalPhysicsThrottle", g_009452a0);
    *(void**)p = (void*)g_0082e2fc;
    fn_00446110(p + 0x30, 0, b, a);
    fn_00446110(p + 0x50, 0, b, a);
    initList(p + 0x70);
    initList(p + 0x88);
    initList(p + 0xa0);
    initList(p + 0xb8);
    initList(p + 0xd0);

    fn_0064d530(self, 0, 0, "DefaultAuto");
    fn_0064d530(self, 0, 1, "Disabled");
    fn_0064d530(self, 0, 2, "Random");
    fn_0064d530(self, 0, 3, "Always");
    return self;
}
