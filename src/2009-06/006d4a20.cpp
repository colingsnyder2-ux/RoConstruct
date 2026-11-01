// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CRITICAL_SECTION { void* a; long b; long c; void* d; void* e; unsigned long f; };
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(CRITICAL_SECTION*);
struct win32_mutex {
    CRITICAL_SECTION mtx;
    win32_mutex() { InitializeCriticalSection(&mtx); }
    ~win32_mutex();
};
struct PODptr {
    char* ptr; unsigned sz;
    PODptr() : ptr(0), sz(0) {}
};
struct pool {
    void* first;
    PODptr list;
    unsigned requested_size;
    unsigned next_size;
    unsigned start_size;
    pool(unsigned nrequested_size, unsigned nnext_size = 32)
        : first(0), requested_size(nrequested_size), next_size(nnext_size), start_size(nnext_size) {}
    ~pool();
};
struct pool_type : win32_mutex {
    pool p;
    pool_type() : p(0x3c, 32) {}
};
struct singleton_default {
    static pool_type& instance();
};
pool_type& singleton_default::instance()
{
    static pool_type obj;
    return obj;
}
