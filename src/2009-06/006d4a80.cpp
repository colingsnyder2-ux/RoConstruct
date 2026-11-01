// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CRITICAL_SECTION { void* a; long b, c; void* d, *e; unsigned long f; };
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CRITICAL_SECTION*);
namespace boost { namespace details { namespace pool {
class win32_mutex {
    CRITICAL_SECTION mtx;
public:
    win32_mutex() { InitializeCriticalSection(&mtx); }
    ~win32_mutex() { DeleteCriticalSection(&mtx); }
};
template <typename T> struct singleton_default {
    static T& instance() { static T obj; return obj; }
};
}}
struct default_user_allocator_new_delete {};
template <typename UA> class pool {
    void* first;
    char* list_ptr;
    unsigned list_sz;
    const unsigned requested_size;
    unsigned next_size;
    unsigned start_size;
public:
    explicit pool(unsigned nrequested_size, unsigned nnext_size = 32)
        : first(0), list_ptr(0), list_sz(0), requested_size(nrequested_size), next_size(nnext_size), start_size(nnext_size) {}
    ~pool();
};
template <typename Tag, unsigned RequestedSize, typename UA = default_user_allocator_new_delete,
          typename Mutex = details::pool::win32_mutex, unsigned NextSize = 32>
struct singleton_pool {
    struct pool_type : Mutex {
        pool<UA> p;
        pool_type() : p(RequestedSize, NextSize) {}
    };
    typedef details::pool::singleton_default<pool_type> singleton;
};
}
class Tag;
template struct boost::details::pool::singleton_default<boost::singleton_pool<Tag, 180>::pool_type>;
