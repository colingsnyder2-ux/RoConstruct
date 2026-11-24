// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the target is a cached factory. It looks up a 24-byte key
// (Vector3, int, Vector2) in a map guarded by a mutex. On a miss it creates
// a new 0x8c-byte object and stores it in the map. On a hit it returns the
// cached pointer.

extern "C" {
void fn_00557330(void (*once)(), long* flag);                       // boost::call_once
void fn_004d98d0();                                                 // once-init routine
extern long g_once_flag_0097274c;
extern char* g_registry_00972734;                                   // singleton registry

void __fastcall fn_00563090(void* mutex, int unusedEdx);            // GuidRegistryMutex::lock
void __fastcall fn_005630e0(void* mutex, int unusedEdx);            // GuidRegistryMutex::unlock
int  __fastcall fn_004e8720(void* self, int unusedEdx, int a1, int a2);
int  __fastcall fn_006a0920(void* self, int unusedEdx, int a1);
int  __fastcall fn_005004d0(void* self, int unusedEdx, int a1, int a2, int a3);
int  __fastcall fn_004ea000(void* self, int unusedEdx, int a1);
void __fastcall fn_00598fa0(void* self, int unusedEdx, int ptr);    // ReferenceCountedPointer<Texture>::setPointer
}

namespace {
struct LockGuard {
    void* m;
    explicit LockGuard(void* mm) : m(mm) { fn_00563090(m, 0); }
    ~LockGuard() { fn_005630e0(m, 0); }
};

struct Key {
    float x, y, z;
    int   i;
    float u, v;
};
}

extern "C" int fn_004ef7b0(const float* a, int b, const float* c)
{
    fn_00557330(fn_004d98d0, &g_once_flag_0097274c);

    char* reg = g_registry_00972734;
    LockGuard guard(reg + 0x10);

    Key key;
    key.x = a[0];
    key.y = a[1];
    key.z = a[2];
    key.i = b;
    key.u = c[0];
    key.v = c[1];

    char* map = reg + 0x3c;

    // equal_range-style lookup: range[0] = lower bound, range[1] = upper bound
    int range[2];
    fn_004e8720(map, 0, (int)range, (int)&key);

    int endMarker = *(int*)(map + 0x18);

    if (range[1] == endMarker) {
        // not found: create and insert
        int mem = fn_006a0920(0, 0, 0x8c);
        int obj = 0;
        if (mem)
            obj = fn_005004d0((void*)mem, 0, (int)a, b, (int)c);
        int slot = fn_004ea000(map, 0, (int)&key);
        fn_00598fa0((void*)slot, 0, obj);
        return obj;
    }

    // found: return cached value stored in the node
    return *(int*)((char*)range[1] + 0x24);
}
