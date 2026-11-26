// from server: 100% by Xemicl
// roc 2012-06 00909c50  unit: RBX::Body  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00909c50
//
// 00909c50  b801000000           mov eax, 1
// 00909c55  84055c68e500         test byte ptr [0xe5685c], al
// 00909c5b  7548                 jne 0x909ca5
// 00909c5d  09055c68e500         or dword ptr [0xe5685c], eax
// 00909c63  682c68e500           push 0xe5682c
// 00909c68  ff15dc21b200         call dword ptr [0xb221dc]
// 00909c6e  33c0                 xor eax, eax
// 00909c70  a34468e500           mov dword ptr [0xe56844], eax
// 00909c75  a34868e500           mov dword ptr [0xe56848], eax
// 00909c7a  a34c68e500           mov dword ptr [0xe5684c], eax
// 00909c7f  b820000000           mov eax, 0x20
// 00909c84  68f00fb200           push 0xb20ff0
// 00909c89  c7055068e500b4000000 mov dword ptr [0xe56850], 0xb4
// 00909c93  a35468e500           mov dword ptr [0xe56854], eax
// 00909c98  a35868e500           mov dword ptr [0xe56858], eax
// 00909c9d  e853950700           call 0x9831f5
// 00909ca2  83c404               add esp, 4
// 00909ca5  b82c68e500           mov eax, 0xe5682c
// 00909caa  c3                   ret 
// copied from an identical function in another client (function ?instance@?$singleton_default@Upool_type@?$singleton_pool@VTag@@$0LE@Udefault_user_allocator_new_delete@boost@@Vwin32_mutex@pool@details@3@$0CA@@boost@@@pool@details@boost@@SAAAUpool_type@?$singleton_pool@VTag@@$0LE@Udefault_user_allocator_new_delete@boost@@Vwin32_mutex@pool@details@3@$0CA@@4@XZ)

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