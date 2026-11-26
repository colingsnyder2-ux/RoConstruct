// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <string>
#include <map>
template <class T> struct PoolAllocator : std::allocator<T> {
    void* pool;
    PoolAllocator() : pool(0) {}
    template <class U> PoolAllocator(const PoolAllocator<U>& o) : pool(o.pool) {}
    template <class U> struct rebind { typedef PoolAllocator<U> other; };
};
template class std::_Tree<std::_Tmap_traits<std::string, int, std::less<std::string>, PoolAllocator<std::pair<const std::string, int> >, false> >;
