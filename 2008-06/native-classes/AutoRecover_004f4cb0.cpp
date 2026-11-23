// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native headers were provided, so every type below is a local reconstruction and unknown callees are declared with the fn_ naming convention.

extern "C" {
    __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
    __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
}

struct Vector3 { float x, y, z; };

struct RCObject {
    void** vtbl;
    volatile long refCount;
};

extern "C" int fn_006a0920(int a1);
extern "C" void fn_004e3570(const float* size, void* vertexBuf, void* indexBuf);
extern "C" void __fastcall fn_00548570(void* self, int unusedEdx);                   // RenderBase::Mesh::Mesh()
extern "C" RCObject* __fastcall fn_004dd2e0(void* self, int unusedEdx, int prim);   // Mesh::Level::Level(Primitive)
extern "C" void __fastcall fn_004dcbb0(void* arr, int unusedEdx, void* rcp);        // Array<RCP<Level>>::append
extern "C" void __fastcall fn_0045ad90(void* self, int unusedEdx);                  // zeroWeakPointers

struct RCP {
    RCObject* p;
    RCP() : p(0) {}
    void set(RCObject* o) {
        p = 0;
        if (o) { p = o; InterlockedIncrement(&o->refCount); }
    }
    ~RCP() {
        if (p) {
            if (InterlockedDecrement(&p->refCount) == 0) {
                fn_0045ad90(p, 0);
                if (p) {
                    typedef void (__thiscall *DelFn)(RCObject*, int);
                    ((DelFn)p->vtbl[0])(p, 1);
                }
            }
            p = 0;
        }
    }
};

// INFERRED: builder layout (ReferenceCountedPointer at +0x10)
struct PBBBuilder {
    char pad[0x10];
    RCP level;
    char pad2[0x10];
};

extern "C" void __fastcall fn_004f1eb0(PBBBuilder* self, int unusedEdx, RCP* level, Vector3 size, int arg2);
extern "C" void __fastcall fn_00500d30(PBBBuilder* self, int unusedEdx, int purpose); // LevelBuilder::build

extern "C" unsigned char g_0096de64;
extern "C" float g_00819bac;
// INFERRED: vtable of the derived mesh class (unknown global)
extern "C" void* g_00827070[];

struct MeshObj {
    void** vtbl;
    char pad[8];
    char levels[0x44];   // Array at +0xc
};

extern "C" MeshObj* __fastcall fn_004f4cb0(MeshObj* self, int unusedEdx, const Vector3* size, int arg2)
{
    fn_00548570(self, 0);
    self->vtbl = g_00827070;

    RCObject* lv = 0;
    int mem = fn_006a0920(0x28);
    if (mem)
        lv = fn_004dd2e0((void*)mem, 0, 5);

    RCP level;
    level.set(lv);
    fn_004dcbb0((char*)self + 0xc, 0, &level);

    {
        PBBBuilder builder;
        fn_004f1eb0(&builder, 0, &level, *size, arg2);
        fn_00500d30(&builder, 0, 0);
    }

    if (g_0096de64) {
        float s = g_00819bac;
        Vector3 t;
        t.x = size->x * s;
        t.y = size->y * s;
        t.z = size->z * s;
        fn_004e3570((char*)self + 0x68, 0, (int)&t, (int)((char*)self + 0x68), (int)((char*)self + 0x50));
    }
    return self;
}
