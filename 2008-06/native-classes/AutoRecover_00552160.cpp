// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a deleting-less destructor body of an RBX render Chunk
// subclass. The original code has an MSVC SEH frame for member-by-member
// unwinding, which is not reproduced here. The frame comes from member
// destructors that may throw, and these helpers are declared as C functions.

extern "C" {
    // INFERRED: global counters (instance count, etc.) at fixed addresses
    extern int g_counter_0097288c;
    extern int g_polygonTotal_00972890;
    extern int g_counter_00972894;

    // INFERRED: vtable symbol at 0x82d258
    extern char g_vtbl_0082d258[];

    unsigned int __fastcall fn_00546320(void* self, int unusedEdx); // ConvexBody::getPolygonCount
    int __fastcall fn_005405d0(void* self, int unusedEdx);
    void __fastcall fn_006433e0(void* self, int unusedEdx);         // G3D::Array<Edge*>::~Array
    void __fastcall fn_00502a70(void* self, int unusedEdx);         // ReferenceCountedPointer::zeroPointer
    void __fastcall fn_0047d410(void* self, int unusedEdx);         // IRenderable::~IRenderable
    void __fastcall fn_004e81d0(void* self, int unusedEdx);         // RenderBase::Chunk::~Chunk
}

extern "C" void __fastcall fn_00552160(void* self, int unusedEdx)
{
    char* p = (char*)self;

    *(void**)p = (void*)g_vtbl_0082d258;

    g_counter_0097288c += 1;
    g_counter_00972894 -= 1;

    g_polygonTotal_00972890 -= (int)fn_00546320(p + 0xf0, 0);
    fn_005405d0(p + 0xf0, 0);

    fn_006433e0(p + 0xe4, 0);
    fn_006433e0(p + 0xd8, 0);
    fn_00502a70(p + 0xb8, 0);
    fn_0047d410(p + 0x30, 0);
    fn_00502a70(p + 0x2c, 0);
    fn_00502a70(p + 0x28, 0);

    fn_004e81d0(self, 0);
}
