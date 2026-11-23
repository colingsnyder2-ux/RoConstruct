// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: all callees are raw externs; the registry layout is read from the disassembly only.
struct Vec3 { float x, y, z; };
struct Vec2 { float x, y; };

struct TorsoKey { Vec3 v; int normalId; Vec2 uv; };

struct Registry {
    char pad[0x10];
    char mutex[0x2c];   // lock object at +0x10
    char map[1];        // map at +0x3c
};

extern "C" void __cdecl fn_00557330(void (*init)(), long* flag);
extern "C" void __cdecl fn_004d9870();
extern "C" void __fastcall fn_00563090(void* self, int unusedEdx);
extern "C" void __fastcall fn_005630e0(void* self, int unusedEdx);
extern "C" int __fastcall fn_004e8720(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_006a0920(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004ea000(void* self, int unusedEdx, int a1);
extern "C" void* __fastcall fn_004fa880(void* self, int unusedEdx, const Vec3* a, int n, const Vec2* b);
extern "C" void __fastcall fn_00598fa0(void* self, int unusedEdx, void* p);

extern Registry* g_torsoRegistry;   // 0x972730
extern long g_torsoRegistryOnce;    // 0x972748

struct Lock {
    void* m;
    explicit Lock(void* mm) : m(mm) { fn_00563090(m, 0); }
    ~Lock() { fn_005630e0(m, 0); }
};

extern "C" void* fn_004ee8b0(const Vec3* pos, int normalId, const Vec2* uv)
{
    fn_00557330(fn_004d9870, &g_torsoRegistryOnce);
    Registry* r = g_torsoRegistry;
    Lock lock(r->mutex);

    TorsoKey key;
    key.v = *pos;
    key.normalId = normalId;
    key.uv = *uv;

    void* map = r->map;
    int found = 0;
    fn_004e8720(map, 0, (int)&found, (int)&key);
    int end = *(int*)((char*)map + 0x18);

    if (found == end) {
        void* mem = (void*)fn_006a0920(0, 0, 0x8c);
        void* mesh = mem ? fn_004fa880(mem, 0, pos, normalId, uv) : 0;
        int slot = fn_004ea000(map, 0, (int)&key);
        fn_00598fa0((void*)slot, 0, mesh);
        return mesh;
    }
    return *(void**)(found + 0x24);
}
