// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <new>
struct CRITICAL_SECTION { void* a; long b, c; void* d, *e; unsigned long f; };
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
namespace boost { namespace details { namespace pool {
class win32_mutex {
    CRITICAL_SECTION mtx;
public:
    win32_mutex() { InitializeCriticalSection(&mtx); }
    ~win32_mutex() { DeleteCriticalSection(&mtx); }
    void lock() { EnterCriticalSection(&mtx); }
    void unlock() { LeaveCriticalSection(&mtx); }
};
template <typename T> struct singleton_default {
    static T& instance();
};
template <typename M> class guard {
    M& mtx;
public:
    explicit guard(M& m) : mtx(m) { mtx.lock(); }
    ~guard() { mtx.unlock(); }
};
}}
struct default_user_allocator_new_delete {};
template <typename UA> class pool {
public:
    void* first;
    char* list_ptr;
    unsigned list_sz;
    const unsigned requested_size;
    unsigned next_size;
    unsigned start_size;
    void* malloc_need_resize() throw();
    void* malloc() {
        if (first != 0) { void* ret = first; first = *static_cast<void**>(first); return ret; }
        return malloc_need_resize();
    }
};
template <typename Tag, unsigned RequestedSize, typename UA = default_user_allocator_new_delete,
          typename Mutex = details::pool::win32_mutex, unsigned NextSize = 32>
struct singleton_pool {
    struct pool_type : Mutex {
        pool<UA> p;
    };
    typedef details::pool::singleton_default<pool_type> singleton;
    static __forceinline void* malloc() {
        pool_type& p = singleton::instance();
        details::pool::guard<Mutex> g(p);
        return p.p.malloc();
    }
};
}
struct Tag;
static long count;
void* allocate() {
    void* p = boost::singleton_pool<Tag, 32>::malloc();
    if (!p) throw std::bad_alloc("singleton_pool allocator failed");
    InterlockedIncrement(&count);
    return p;
}
