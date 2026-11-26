// from server: 100% by Xemicl
// roc 2012-06 004729b0  unit: CRobloxApp  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004729b0
//
// 004729b0  b801000000           mov eax, 1
// 004729b5  840520a3e100         test byte ptr [0xe1a320], al
// 004729bb  7543                 jne 0x472a00
// 004729bd  090520a3e100         or dword ptr [0xe1a320], eax
// 004729c3  68f0a2e100           push 0xe1a2f0
// 004729c8  ff15dc21b200         call dword ptr [0xb221dc]
// 004729ce  33c0                 xor eax, eax
// 004729d0  a308a3e100           mov dword ptr [0xe1a308], eax
// 004729d5  a30ca3e100           mov dword ptr [0xe1a30c], eax
// 004729da  a310a3e100           mov dword ptr [0xe1a310], eax
// 004729df  b820000000           mov eax, 0x20
// 004729e4  688026b100           push 0xb12680
// 004729e9  a314a3e100           mov dword ptr [0xe1a314], eax
// 004729ee  a318a3e100           mov dword ptr [0xe1a318], eax
// 004729f3  a31ca3e100           mov dword ptr [0xe1a31c], eax
// 004729f8  e8f8075100           call 0x9831f5
// 004729fd  83c404               add esp, 4
// 00472a00  b8f0a2e100           mov eax, 0xe1a2f0
// 00472a05  c3                   ret 
// copied from an identical function in another client (function ?instance@?$singleton_default@Upool_type@?$singleton_pool@VLuaAllocator@@$0CA@Udefault_user_allocator_new_delete@boost@@Vwin32_mutex@pool@details@3@$0CA@@boost@@@pool@details@boost@@SAAAUpool_type@?$singleton_pool@VLuaAllocator@@$0CA@Udefault_user_allocator_new_delete@boost@@Vwin32_mutex@pool@details@3@$0CA@@4@XZ)

// from server: 100% by EspClaude
// roc 2009-06 00448fa0  size: 86 bytes
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
class LuaAllocator;
template struct boost::details::pool::singleton_default<boost::singleton_pool<LuaAllocator, 32>::pool_type>;