// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <vector>
#include <string>
namespace Ogre {
class __declspec(dllimport) NedPoolingImpl {
public:
    static void* allocBytes(size_t count, const char* file, int line, const char* func);
    static void deallocBytes(void* ptr);
};
template<class T> class STLAllocator {
public:
    typedef T value_type; typedef T* pointer; typedef const T* const_pointer;
    typedef T& reference; typedef const T& const_reference;
    typedef size_t size_type; typedef ptrdiff_t difference_type;
    template<class U> struct rebind { typedef STLAllocator<U> other; };
    STLAllocator() {}
    STLAllocator(const STLAllocator&) {}
    template<class U> STLAllocator(const STLAllocator<U>&) {}
    pointer allocate(size_type n, const void* = 0) { return (pointer)NedPoolingImpl::allocBytes(n * sizeof(T), 0, 0, 0); }
    void deallocate(pointer p, size_type) { NedPoolingImpl::deallocBytes(p); }
    pointer address(reference x) const { return &x; }
    const_pointer address(const_reference x) const { return &x; }
    size_type max_size() const { return 0x7fffffff / sizeof(T); }
    void construct(pointer p, const T& v) { new ((void*)p) T(v); }
    void destroy(pointer p) { p->~T(); }
};
template<class T,class U> bool operator==(const STLAllocator<T>&, const STLAllocator<U>&) { return true; }
template<class T,class U> bool operator!=(const STLAllocator<T>&, const STLAllocator<U>&) { return false; }
}
template class std::vector<std::string, Ogre::STLAllocator<std::string> >;
