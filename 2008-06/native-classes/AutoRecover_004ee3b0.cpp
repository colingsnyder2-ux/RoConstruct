// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: header-free sketch; types are opaque, layouts taken from the disassembly.
struct Vec3 { float x, y, z; };
struct Vec2 { float x, y; };

struct WedgeKey { float x, y, z; int face; float u, v; };

struct Registry {
    char pad[0x10];
    char mutex[0x2c];   // lock object at +0x10
    char map[1];        // cache map at +0x3c
};

extern "C" void __cdecl fn_004d9930();
extern "C" void __cdecl fn_00557330(void (__cdecl*)(), long*);   // boost::call_once
extern "C" Registry* g_00972738;
extern long g_00972750;
extern "C" void __fastcall fn_00563090(void* self, int unusedEdx);   // GuidRegistryMutex::lock
extern "C" void __fastcall fn_005630e0(void* self, int unusedEdx);   // unlock
extern "C" int __fastcall fn_004e8720(void* self, int unusedEdx, int a1, int a2);
extern "C" void* __fastcall fn_006a0920(void* self, int unusedEdx, int a1);
extern "C" void* __fastcall fn_004ea000(void* self, int unusedEdx, int a1);
extern "C" void __fastcall fn_00598fa0(void* self, int unusedEdx, void* p);  // setPointer
extern "C" void* __fastcall fn_004f7a30(void* self, int unusedEdx, const Vec3* a, int face, const Vec2* c);

struct Lock {
    void* m;
    explicit Lock(void* mm) : m(mm) { fn_00563090(m, 0); }
    ~Lock() { fn_005630e0(m, 0); }
};

extern "C" void* fn_004ee3b0(const Vec3* pos, int face, const Vec2* uv)
{
    fn_00557330(fn_004d9930, &g_00972750);
    Registry* r = g_00972738;
    Lock lock(r->mutex);

    WedgeKey key;
    key.x = pos->x; key.y = pos->y; key.z = pos->z;
    key.face = face;
    key.u = uv->x; key.v = uv->y;

    int found[2];
    fn_004e8720(r->map, 0, (int)found, (int)&key);

    if (found[1] == ((int*)r->map)[0x18 / 4]) {
        void* mem = fn_006a0920(0, 0, 0x8c);
        void* mesh = mem ? fn_004f7a30(mem, 0, pos, face, uv) : 0;
        void* slot = fn_004ea000(r->map, 0, (int)&key);
        fn_00598fa0(slot, 0, mesh);
        return mesh;
    }
    return ((void**)found[1])[0x24 / 4];
}
