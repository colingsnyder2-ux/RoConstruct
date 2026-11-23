// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: all types below are reconstructed from the disassembly only; no class headers were available.

struct CacheKey {
    float a[3];   // copied from arg0 (3 floats)
    int   b;      // arg1
    float c[2];   // copied from arg2 (2 floats)
};

struct MapIter {
    void* proxy;  // [esp+0x10]
    char* node;   // [esp+0x14]
};

extern "C" {
    void fn_00557330(void (*initFn)(), long* flag);                              // boost::call_once
    void __fastcall fn_00563090(void* mutex, int unusedEdx);                     // GuidRegistryMutex::lock
    void __fastcall fn_005630e0(void* mutex, int unusedEdx);                     // GuidRegistryMutex::unlock
    int  __fastcall fn_004e8720(void* self, int unusedEdx, int a1, int a2);      // map find(out, key)
    int  __fastcall fn_004fd960(void* self, int unusedEdx, int a1, int a2, int a3); // object ctor
    int  __fastcall fn_004ea000(void* self, int unusedEdx, int a1);              // map operator[]
    void __fastcall fn_00598fa0(void* self, int unusedEdx, int ptr);             // ReferenceCountedPointer<Texture>::setPointer
    // INFERRED: the caller pops its own argument, so this is really a cdecl allocator.
    void* fn_006a0920(unsigned size);
    void fn_004d9810();
}

// INFERRED: globals at 0x972744 (once flag) and 0x97272c (registry pointer)
extern long  g_onceFlag_00972744;
extern char* g_registry_0097272c;

struct MutexGuard {
    void* m;
    explicit MutexGuard(void* mm) : m(mm) { fn_00563090(m, 0); }
    ~MutexGuard() { fn_005630e0(m, 0); }
};

extern "C" int fn_004ef2b0(const float* vec3, int arg1, const float* vec2)
{
    fn_00557330(fn_004d9810, &g_onceFlag_00972744);
    char* reg = g_registry_0097272c;
    MutexGuard guard(reg + 0x10);

    CacheKey key;
    key.a[0] = vec3[0];
    key.a[1] = vec3[1];
    key.a[2] = vec3[2];
    key.b = arg1;
    key.c[0] = vec2[0];
    key.c[1] = vec2[1];

    char* map = reg + 0x3c;
    MapIter it;
    fn_004e8720(map, 0, (int)&it, (int)&key);
    char* endNode = *(char**)(map + 0x18);

    if (it.node == endNode) {
        void* mem = fn_006a0920(0x8c);
        int obj = 0;
        if (mem)
            obj = fn_004fd960(mem, 0, (int)vec3, arg1, (int)vec2);
        int ref = fn_004ea000(map, 0, (int)&key);
        fn_00598fa0((void*)ref, 0, obj);
        return obj;
    }

    // INFERRED: value stored in the node at +0x24
    return *(int*)(it.node + 0x24);
}
