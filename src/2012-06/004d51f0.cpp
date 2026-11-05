// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <map>
#include <new>

// Stateful 4-byte allocator: puts _Myhead at this+0x10 (comp, _Alnod, _Alptr, _Alval before it).
template<class T> struct StatefulAlloc {
    typedef T value_type; typedef T* pointer; typedef const T* const_pointer;
    typedef T& reference; typedef const T& const_reference;
    typedef unsigned int size_type; typedef int difference_type;
    template<class U> struct rebind { typedef StatefulAlloc<U> other; };
    void* state;
    StatefulAlloc() : state(0) {}
    template<class U> StatefulAlloc(const StatefulAlloc<U>& o) : state(o.state) {}
    pointer address(reference x) const { return &x; }
    const_pointer address(const_reference x) const { return &x; }
    pointer allocate(size_type n) { return (pointer)operator new(n * sizeof(T)); }
    pointer allocate(size_type n, const void*) { return allocate(n); }
    void deallocate(pointer p, size_type) { operator delete(p); }
    void construct(pointer p, const T& v) { new ((void*)p) T(v); }
    void destroy(pointer p) { p->~T(); }
    size_type max_size() const { return 0x7fffffff / sizeof(T); }
};
template<class T, class U> bool operator==(const StatefulAlloc<T>&, const StatefulAlloc<U>&) { return true; }
template<class T, class U> bool operator!=(const StatefulAlloc<T>&, const StatefulAlloc<U>&) { return false; }

// isnil at node+0x2d (value_type 0x20); _Myhead at this+0x10
struct Value16 { int words[7]; };
template class std::_Tree<std::_Tmap_traits<int, Value16, std::less<int>,
    StatefulAlloc<std::pair<const int, Value16> >, false> >;
