// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were available, so the layout is described only by raw offsets.

extern "C" int fn_006a0920(int a1);
extern "C" void __fastcall fn_0056c590(void* self, int unusedEdx, const char* name, const void* typeInfo);
extern "C" void __fastcall fn_00446110(void* self, int unusedEdx, char* a, char* b);
extern "C" void __fastcall fn_0064d530(void* self, int unusedEdx, int value, const char* name);

// INFERRED: type_info of the enum type lives at 0x95203c
extern "C" char g_0095203c[];
// INFERRED: vtable of the BinType enum descriptor
extern "C" char g_0083aeb4[];

// INFERRED: 0x18-byte container (head node pointer at +0, size-like fields at +0xc..+0x14)
static inline void initContainer(char* base)
{
    int* node = (int*)fn_006a0920(4);
    int head;
    if (node != 0) {
        *node = (int)base;
        head = (int)node;
    } else {
        head = 0;
    }
    *(int*)base = head;
    *(int*)(base + 0x0c) = 0;
    *(int*)(base + 0x10) = 0;
    *(int*)(base + 0x14) = 0;
}

extern "C" void* __fastcall fn_005d0140(void* self, int unusedEdx)
{
    char* p = (char*)self;
    char a, b;

    fn_0056c590(self, 0, "BinType", (const void*)g_0095203c);
    *(void**)p = (void*)g_0083aeb4; // INFERRED: vtable of the BinType descriptor
    fn_00446110(p + 0x30, 0, &b, &a);
    fn_00446110(p + 0x50, 0, &b, &a);
    initContainer(p + 0x70);
    initContainer(p + 0x88);
    initContainer(p + 0xa0);
    initContainer(p + 0xb8);
    initContainer(p + 0xd0);

    fn_0064d530(self, 0, 0, "Script");
    fn_0064d530(self, 0, 1, "GameTool");
    fn_0064d530(self, 0, 2, "Grab");
    fn_0064d530(self, 0, 3, "Clone");
    fn_0064d530(self, 0, 4, "Hammer");
    fn_0064d530(self, 0, 5, "Slingshot");
    fn_0064d530(self, 0, 6, "Rocket");
    fn_0064d530(self, 0, 7, "Laser");
    return self;
}
