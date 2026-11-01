// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
typedef unsigned int size_t;
struct T80 { char b[80]; };
template<class T> struct alloc { size_t max_size() const; };
template<class T> size_t alloc<T>::max_size() const { size_t _Count = (size_t)(-1) / sizeof (T); return (0 < _Count ? _Count : 1); }
template struct alloc<T80>;
