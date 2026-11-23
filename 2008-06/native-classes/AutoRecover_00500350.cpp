// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header available; types are opaque stand-ins and the layout is guessed from the disassembly.
// INFERRED: most helpers keep their fn_ names with opaque arguments. This is a codegen analog, not a verified match.

extern "C" {
    void __fastcall fn_00548570(void* self, int unusedEdx);                 // Mesh::Mesh()
    int fn_006a0920(int size);                                              // operator new
    void* __fastcall fn_004dd2e0(void* self, int unusedEdx, int primitive); // Level::Level(Primitive)
    void __fastcall fn_004dcbb0(void* arr, int unusedEdx, void* ptrRef);    // Array<RCP<Level>>::append
    void __fastcall fn_00598fa0(void* self, int unusedEdx, void* tex);      // RCP<Texture>::setPointer
    int __fastcall fn_004fdaf0(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
    void __fastcall fn_00500ca0(void* self, int unusedEdx, int face, int purpose); // LevelBuilder::buildFace
    void __fastcall fn_0045ad90(void* self, int unusedEdx);                 // zeroWeakPointers
    long __stdcall InterlockedIncrement(long volatile*);
    long __stdcall InterlockedDecrement(long volatile*);

    // INFERRED: vtable of this mesh class (unknown global, stored as the object's vptr)
    extern void* g_008271b8[];
    // INFERRED: float scale constant used on the picked size component
    extern const float g_0083a3e4;
}

struct Level { void** vtbl; long refCount; };

struct BoxMesh {
    void** vtbl;
};

extern "C" BoxMesh* __fastcall fn_00500350(BoxMesh* self, int unusedEdx, const float* size, int face)
{
    fn_00548570(self, 0);
    self->vtbl = g_008271b8;

    // INFERRED: picks the larger of size.x and size.z, scaled
    const float* pick = (size[0] > size[2]) ? size : size + 2;
    float scaled = *pick * g_0083a3e4;

    Level* level = 0;
    void* mem = (void*)fn_006a0920(0x28);
    if (mem)
        level = (Level*)fn_004dd2e0(mem, 0, 5);

    if (level)
        InterlockedIncrement(&level->refCount);
    fn_004dcbb0((char*)self + 0xc, 0, &level);
    if (level && InterlockedDecrement(&level->refCount) == 0) {
        fn_0045ad90(level, 0);
        ((void (__thiscall*)(Level*, int))level->vtbl[0])(level, 1);
    }

    // INFERRED: LevelBuilder is a stack object built by fn_004fdaf0
    char builder[0x30];
    fn_004fdaf0(builder, 0, 0, 0, 9, 0, 0, 0, 0);
    fn_00500ca0(builder, 0, face, 1);
    (void)scaled;
    return self;
}
