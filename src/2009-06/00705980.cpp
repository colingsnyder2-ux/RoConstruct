// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap();
extern "C" __declspec(dllimport) void* __stdcall HeapAlloc(void*, unsigned long, unsigned long);
extern "C" __declspec(dllimport) int __stdcall HeapFree(void*, unsigned long, void*);
#include <new>
#include <string>
namespace boost {
namespace detail {
inline void* allocate_raw_heap_memory(unsigned size)
{
    void* const heap_memory = HeapAlloc(GetProcessHeap(), 0, size);
    if (!heap_memory) throw std::bad_alloc();
    return heap_memory;
}
inline void free_raw_heap_memory(void* heap_memory) { HeapFree(GetProcessHeap(), 0, heap_memory); }
template<typename T> T* heap_new()
{
    void* const heap_memory = allocate_raw_heap_memory(sizeof(T));
    try { T* const data = new (heap_memory) T(); return data; }
    catch (...) { free_raw_heap_memory(heap_memory); throw; }
}
struct tss_cleanup_function { virtual ~tss_cleanup_function() {} virtual void operator()(void* data) = 0; };
}
template<typename T> class thread_specific_ptr {
public:
    struct delete_data : detail::tss_cleanup_function { void operator()(void* data) { delete static_cast<T*>(data); } };
};
template thread_specific_ptr<std::string>::delete_data* detail::heap_new<thread_specific_ptr<std::string>::delete_data>();
}
