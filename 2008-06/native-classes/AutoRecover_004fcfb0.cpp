// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native headers were available for this class, so every type
// below is a local stand-in and all callees use the fn_<addr> convention.

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct Level {
    void** vtbl;
    volatile long refCount;
};

struct LevelPtr {
    Level* p;
};

struct LevelArray {
    LevelPtr* data;
    int size;
};

struct Vec3 {
    float x, y, z;
};

// INFERRED: the target is a Mesh subclass constructor; layout reconstructed from offsets only.
struct MeshObj {
    void** vtbl;          // 0x00
    int    pad0[2];       // 0x04
    LevelArray levels;    // 0x0c
    char   pad1[0x84 - 0x14];
    int    kind;          // 0x84
};

// INFERRED: LevelBuilder layout from offsets: vtable at 0, level ref at 0x14, mode at 0x20.
struct LevelBuilderObj {
    void** vtbl;          // 0x00
    int   pad0[4];        // 0x04
    Level* level;         // 0x14
    int   pad1[2];        // 0x18
    int   mode;           // 0x20
    int   pad2[2];        // 0x24
};

// INFERRED: vtables of the derived mesh class and the derived level builder.
extern "C" void* g_00827154[];
extern "C" void* g_00827134[];

extern "C" int  fn_006a0920(int a1);
extern "C" void __fastcall fn_00548570(MeshObj* self, int unusedEdx);                       // RBX::RenderBase::Mesh::Mesh()
extern "C" Level* __fastcall fn_004dd2e0(Level* self, int unusedEdx, int primitive);        // Mesh::Level::Level(Primitive)
extern "C" void __fastcall fn_004dcbb0(LevelArray* self, int unusedEdx, LevelPtr* item);    // Array<RCP<Level>>::append
extern "C" void __fastcall fn_00500d80(LevelBuilderObj* self, int unusedEdx, LevelPtr* level, Vec3 size, int arg); // LevelBuilder ctor
extern "C" void __fastcall fn_00500d30(void* self, int unusedEdx, int purpose);             // LevelBuilder::build
extern "C" void __fastcall fn_0045ad90(Level* self, int unusedEdx);                         // zeroWeakPointers

static inline void releaseLevel(Level* l)
{
    if (l) {
        if (InterlockedDecrement(&l->refCount) == 0) {
            fn_0045ad90(l, 0);
            typedef void (__fastcall *DtorFn)(Level*, int, int);
            ((DtorFn)l->vtbl[0])(l, 0, 1);
        }
    }
}

extern "C" MeshObj* __fastcall fn_004fcfb0(MeshObj* self, int unusedEdx, const Vec3* size, int arg)
{
    fn_00548570(self, 0);
    self->vtbl = g_00827154;
    self->kind = 2;

    Level* lvl = 0;
    void* mem = (void*)fn_006a0920(0x28);
    if (mem)
        lvl = fn_004dd2e0((Level*)mem, 0, 5);

    LevelPtr tmp;
    tmp.p = lvl;
    if (lvl)
        InterlockedIncrement(&lvl->refCount);

    fn_004dcbb0(&self->levels, 0, &tmp);

    {
        Level* t = tmp.p;
        if (t) {
            releaseLevel(t);
        }
    }

    Vec3 sz = *size;
    LevelBuilderObj builder;
    fn_00500d80(&builder, 0, &self->levels.data[self->levels.size - 1], sz, arg);
    builder.vtbl = g_00827134;
    builder.mode = 6;
    fn_00500d30((char*)&builder + 4, 0, 0);

    releaseLevel(builder.level);
    return self;
}
