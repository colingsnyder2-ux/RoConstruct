// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /GS- /EHsc /MD
#include <memory>
namespace boost {
template<class T> struct has_trivial_destructor { static const bool value = true; };
namespace numeric { namespace ublas {
typedef unsigned int size_type;
class nonassignable { protected: nonassignable() {} ~nonassignable() {} };
template<class E> class storage_array : private nonassignable {};
template<class I> void iterator_destroy(I& i) { typedef double V; (&(*i))->~V(); }
template<class T, class ALLOC = std::allocator<T> >
class unbounded_array : public storage_array<unbounded_array<T, ALLOC> > {
public:
    typedef T* iterator;
    typedef T value_type;
    ~unbounded_array() {
        if (size_) {
            if (!boost::has_trivial_destructor<T>::value) {
                const iterator i_end = end();
                for (iterator i = begin(); i != i_end; ++i) {
                    iterator_destroy(i);
                }
            }
            alloc_.deallocate(data_, size_);
        }
    }
    iterator begin() { return data_; }
    iterator end() { return data_ + size_; }
    ALLOC alloc_; size_type size_; T* data_;
};
template class unbounded_array<double>;
}}}
