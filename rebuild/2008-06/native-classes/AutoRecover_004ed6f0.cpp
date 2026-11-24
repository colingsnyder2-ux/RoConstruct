// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layouts below are guesses from the disassembly. This draft is not byte-matched.
// INFERRED: singleton at 0x972734 built by call_once(0x4d98d0, flag 0x97274c).
// INFERRED: the singleton holds a hash table of nodes and two std::map members. Each node has a
// refcounted slot that is released while iterating.

struct RefCounted {
    virtual void* destroyNode() = 0;
    virtual void destroy(int del) = 0;
};

struct GuidRegistryMutex {
    void lock();
    void unlock();
};

namespace boost { void call_once(void (*fn)(), long& flag); }

extern "C" void fn_004d98d0();
extern long g_guidOnceFlag;      // 0x97274c
extern char* g_guidRegistry;     // 0x972734
extern "C" int __fastcall fn_004e6cf0(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004e6c90(void* self, int unusedEdx, int a1, int a2);

extern "C" void fn_004ed6f0()
{
    boost::call_once(fn_004d98d0, g_guidOnceFlag);
    char* reg = g_guidRegistry;
    GuidRegistryMutex* m = (GuidRegistryMutex*)(reg + 0x10);
    m->lock();

    // INFERRED: outer iteration over the buckets at reg+8, count at reg+0xc;
    // per node the inner slots are released via fn_004e6cf0/fn_004e6c90 helpers.
    int count = *(int*)(reg + 0xc);
    void** buckets = *(void***)(reg + 8);
    for (int i = 0; i < count; ++i) {
        char* node = (char*)buckets[i];
        if (!node)
            continue;
        int zero = 0;
        fn_004e6cf0(node + 8, 0, (int)&zero, 0);
    }
    fn_004e6c90(reg, 0, 0, 0);

    m->unlock();
}
