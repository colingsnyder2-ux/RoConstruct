// from server: 100% by Xemicl
// roc 2012-06 0082b6c0  unit: RBX::BallBallContact  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0082b6c0
//
// 0082b6c0  b801000000           mov eax, 1
// 0082b6c5  84056812e500         test byte ptr [0xe51268], al
// 0082b6cb  7548                 jne 0x82b715
// 0082b6cd  09056812e500         or dword ptr [0xe51268], eax
// 0082b6d3  683812e500           push 0xe51238
// 0082b6d8  ff15dc21b200         call dword ptr [0xb221dc]
// 0082b6de  33c0                 xor eax, eax
// 0082b6e0  a35012e500           mov dword ptr [0xe51250], eax
// 0082b6e5  a35412e500           mov dword ptr [0xe51254], eax
// 0082b6ea  a35812e500           mov dword ptr [0xe51258], eax
// 0082b6ef  b820000000           mov eax, 0x20
// 0082b6f4  6850ebb100           push 0xb1eb50
// 0082b6f9  c7055c12e500e4000000 mov dword ptr [0xe5125c], 0xe4
// 0082b703  a36012e500           mov dword ptr [0xe51260], eax
// 0082b708  a36412e500           mov dword ptr [0xe51264], eax
// 0082b70d  e8e37a1500           call 0x9831f5
// 0082b712  83c404               add esp, 4
// 0082b715  b83812e500           mov eax, 0xe51238
// 0082b71a  c3                   ret 
// copied from an identical function in another client (function ?instance@?$singleton_default@Upool_type@?$singleton_pool@VPrimitive@RBX@@$0OE@Udefault_user_allocator_new_delete@boost@@Vwin32_mutex@pool@details@4@$0CA@@boost@@@pool@details@boost@@SAAAUpool_type@?$singleton_pool@VPrimitive@RBX@@$0OE@Udefault_user_allocator_new_delete@boost@@Vwin32_mutex@pool@details@4@$0CA@@4@XZ)

// from server: 100% by EspClaude
// roc 2009-06 00671240  size: 86 bytes
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
namespace RBX { class Primitive; }
template struct boost::details::pool::singleton_default<boost::singleton_pool<RBX::Primitive, 0xe4>::pool_type>;