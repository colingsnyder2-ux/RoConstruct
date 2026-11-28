// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <crtdefs.h>
#include <stdlib.h>
// INFERRED: no native header for the mesh cache, so locals use Local_ types and fn_ externs.
extern "C" {
void __cdecl fn_00557330(void (*init)(), long* flag);                 // boost::call_once
void __fastcall fn_00563090(void* mutex, int unusedEdx);              // GuidRegistryMutex::lock
void __fastcall fn_005630e0(void* mutex, int unusedEdx);              // GuidRegistryMutex::unlock
int __fastcall fn_004e8690(void* self, int unusedEdx, int a1, int a2);
void* __fastcall fn_006a0920(void* self, int unusedEdx, int a1);
int __fastcall fn_004ea140(void* self, int unusedEdx, int a1);
void* __fastcall fn_004f49d0(void* self, int unusedEdx, const float* v, int normalId); // PBBMesh ctor
void __fastcall fn_00598fa0(void* self, int unusedEdx, void* p);      // setPointer
void fn_004d9750();
extern long g_0097273c;
extern char* g_00972724;
}

struct Local_004edd50Key {
    float x, y, z;
    int normalId;
};

// INFERRED: debug-checked std::map iterator (container, node), as the _invalid_parameter_noinfo calls show.
struct Local_004edd50Iter {
    char* cont;
    char* node;
};

// INFERRED: scoped lock with a locked flag at +4 (stack slot next to the mutex pointer).
struct Local_004edd50Lock {
    void* m;
    bool locked;
    __forceinline explicit Local_004edd50Lock(void* mm) : m(mm) { fn_00563090(m, 0); locked = true; }
    __forceinline ~Local_004edd50Lock() { fn_005630e0(m, 0); }
};

extern "C" void* __cdecl fn_004edd50(const float* v, int normalId)
{
    fn_00557330(fn_004d9750, &g_0097273c);
    char* inst = g_00972724;
    Local_004edd50Lock lock(inst + 0x10);

    char* map = inst + 0x1c;
    Local_004edd50Key key;
    key.x = v[0];
    key.y = v[1];
    key.z = v[2];
    key.normalId = normalId;

    Local_004edd50Iter it;
    fn_004e8690(map, 0, (int)&it, (int)&key);
    char* endNode = *(char**)(map + 0x18);
    char* endCont = *(char**)map;
    if (it.cont == 0 || it.cont != endCont)
        _invalid_parameter_noinfo();
    if (it.node == endNode) {
        void* mem = fn_006a0920(0, 0, 0x8c);
        void* mesh = mem ? fn_004f49d0(mem, 0, v, normalId) : 0;
        int slot = fn_004ea140(map, 0, (int)&key);
        fn_00598fa0((void*)slot, 0, mesh);
        return mesh;
    }
    char* c = it.cont;
    if (c == 0)
        _invalid_parameter_noinfo();
    else
        c = *(char**)c;
    if (it.node == *(char**)(c + 0x18))
        _invalid_parameter_noinfo();
    return *(void**)(it.node + 0x1c);
}
