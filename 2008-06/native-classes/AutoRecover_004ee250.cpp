// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: WedgeMesh factory with a (size, NormalId) keyed cache behind a mutex.
// All types are guesses; no authentic headers were provided.

struct Vec3 { float x, y, z; };

extern "C" int __fastcall fn_004e8690(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_006a0920(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004ea140(void* self, int unusedEdx, int a1);
extern "C" void fn_00557330(void (*fn)(), long* flag);
extern "C" void __fastcall fn_00563090(void* self, int unusedEdx);
extern "C" void __fastcall fn_005630e0(void* self, int unusedEdx);
extern "C" void* __fastcall fn_004f78d0(void* self, int unusedEdx, const Vec3* size, int normalId);
extern "C" void __fastcall fn_00598fa0(void* self, int unusedEdx, void* p);
extern "C" void fn_004d9930();

extern long g_wedgeOnce;      // INFERRED: 0x972750 call_once flag
extern char* g_wedgeRegistry; // INFERRED: 0x972738 singleton

struct WedgeKey { float x, y, z; int id; };

extern "C" void* fn_004ee250(const Vec3* size, int normalId)
{
    fn_00557330(fn_004d9930, &g_wedgeOnce);
    char* reg = g_wedgeRegistry;
    void* mutex = reg + 0x10;
    char* map = reg + 0x1c;
    fn_00563090(mutex, 0);

    WedgeKey key;
    key.x = size->x;
    key.y = size->y;
    key.z = size->z;
    key.id = normalId;

    char* found;
    fn_004e8690(map, 0, (int)&found, (int)&key);
    char* end = *(char**)(map + 0x18);

    void* result;
    if (found == end) {
        void* mem = (void*)fn_006a0920(0, 0, 0x8c);
        result = mem ? fn_004f78d0(mem, 0, size, normalId) : 0;
        int slot = fn_004ea140(map, 0, (int)&key);
        fn_00598fa0((void*)slot, 0, result);
    } else {
        result = *(void**)(found + 0x1c);
    }
    fn_005630e0(mutex, 0);
    return result;
}
