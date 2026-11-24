// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: guid-registry style cache: lookup by 6-dword key, create on miss. Types approximate.
#include <stddef.h>

namespace boost { void call_once(void (*f)(), long& flag); }
namespace RBX {
struct GuidRegistryMutex {
    void lock();
    void unlock();
};
}

extern "C" int __fastcall fn_004e8720(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_006a0920(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004fd270(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int __fastcall fn_004ea000(void* self, int unusedEdx, int a1);
extern "C" void fn_004d97b0();
extern "C" void __fastcall fn_00598fa0(void* self, int unusedEdx, int p);
extern long g_00972740;
extern char* g_00972728;

struct Key {
    float x, y, z;
    int id;
    float u, v;
};

struct Iter {
    void* node;
    void* cont;
};

extern "C" int fn_004eedb0(const float* a, int id, const float* b)
{
    boost::call_once(fn_004d97b0, g_00972740);
    char* reg = g_00972728;
    RBX::GuidRegistryMutex* m = (RBX::GuidRegistryMutex*)(reg + 0x10);
    m->lock();
    Key key;
    key.x = a[0];
    key.y = a[1];
    key.z = a[2];
    key.id = id;
    key.u = b[0];
    key.v = b[1];
    char* map = reg + 0x3c;
    Iter it;
    fn_004e8720(map, 0, (int)&it, (int)&key);
    int result;
    if (it.node == *(void**)(map + 0x18) /* end */) {
        void* mem = (void*)fn_006a0920(0, 0, 0x8c);
        result = mem ? fn_004fd270(mem, 0, (int)a, id, (int)b) : 0;
        int slot = fn_004ea000(map, 0, (int)&key);
        fn_00598fa0((void*)slot, 0, result);
    } else {
        result = *(int*)((char*)it.node + 0x24);
    }
    m->unlock();
    return result;
}
