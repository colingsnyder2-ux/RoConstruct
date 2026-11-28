// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no native headers were available for this class, so the layout and the
// callee signatures below are reconstructed from the disassembly alone.
// The disassembly has SEH states 0..0xc, so the original has member destructors that
// this version does not reproduce.

struct TreeHead {
    void* head;      // +0x00 sentinel node pointer
    int   pad[2];    // +0x04, +0x08
    int   f0c;       // +0x0c
    int   f10;       // +0x10
    int   f14;       // +0x14
};

struct ErrorReportingEnumDesc {
    void*    vtable;          // +0x00
    char     base[0x2c];      // +0x04 .. +0x2f (base EnumDescriptor data)
    char     mapA[0x20];      // +0x30
    char     mapB[0x20];      // +0x50
    TreeHead t0;              // +0x70
    TreeHead t1;              // +0x88
    TreeHead t2;              // +0xa0
    TreeHead t3;              // +0xb8
    TreeHead t4;              // +0xd0
};

extern "C" int fn_006a0920(int a1);
extern "C" void __fastcall fn_0056c590(void* self, int unusedEdx, const char* name, const void* typeInfo);
extern "C" void __fastcall fn_00446110(void* self, int unusedEdx, void* a, void* b);
extern "C" void __fastcall fn_0064d530(void* self, int unusedEdx, int value, const char* name);

extern char g_009452c4[];
extern char g_0082e308[];
extern char g_0082e3a0[];
extern char g_0082e390[];
extern char g_0082e380[];

static inline void initTree(TreeHead* t)
{
    void** node = (void**)fn_006a0920(4);
    if (node)
        *node = t;
    else
        node = 0;
    t->head = node;
    t->f0c = 0;
    t->f10 = 0;
    t->f14 = 0;
}

extern "C" ErrorReportingEnumDesc* __fastcall fn_00564d70(ErrorReportingEnumDesc* self, int unusedEdx)
{
    char tmpA;
    char tmpB;

    fn_0056c590(self, 0, g_0082e3a0, g_009452c4);
    self->vtable = g_0082e308;
    fn_00446110(self->mapA, 0, &tmpA, &tmpB);
    fn_00446110(self->mapB, 0, &tmpA, &tmpB);
    initTree(&self->t0);
    initTree(&self->t1);
    initTree(&self->t2);
    initTree(&self->t3);
    initTree(&self->t4);
    fn_0064d530(self, 0, 0, g_0082e390);
    fn_0064d530(self, 0, 1, g_0082e380);
    return self;
}
