// from server: 95% by EspClaude
// boost 1.36 thread heap_new_impl<tss_data_node> (self-contained)
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS /EHsc /MD
#include <new>
#include <intrin.h>
extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap();
extern "C" __declspec(dllimport) void* __stdcall HeapAlloc(void*, unsigned long, unsigned long);
namespace boost {
namespace detail {
struct sp_counted_base { virtual void dispose()=0; long use_count_; long weak_count_; };
struct shared_count {
    sp_counted_base* pi_;
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count();
};
}
template<class T> class shared_ptr { public: T* px; detail::shared_count pn; };
namespace detail {
struct tss_cleanup_function;
struct tss_data_node {
    tss_data_node(void const* k, boost::shared_ptr<tss_cleanup_function> f, void* v, tss_data_node* n);
    void const* key; boost::shared_ptr<tss_cleanup_function> func; void* value; tss_data_node* next;
};
void free_raw_heap_memory(void* heap_memory);
inline void* allocate_raw_heap_memory(unsigned size)
{
    void* const heap_memory = HeapAlloc(GetProcessHeap(), 0, size);
    if (!heap_memory) throw std::bad_alloc();
    return heap_memory;
}
template<typename T, typename A1, typename A2, typename A3, typename A4>
T* heap_new_impl(A1 a1, A2 a2, A3 a3, A4 a4)
{
    void* const heap_memory = allocate_raw_heap_memory(sizeof(T));
    try {
        T* const data = new (heap_memory) T(a1, a2, a3, a4);
        return data;
    } catch (...) {
        free_raw_heap_memory(heap_memory);
        throw;
    }
}
template tss_data_node* heap_new_impl<tss_data_node, void const*&, boost::shared_ptr<tss_cleanup_function>&, void*&, tss_data_node*&>(void const*&, boost::shared_ptr<tss_cleanup_function>&, void*&, tss_data_node*&);
}
}
