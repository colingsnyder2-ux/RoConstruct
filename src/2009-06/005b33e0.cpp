// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /GS- /EHsc /MD
#include <memory>
namespace boost { namespace numeric { namespace ublas {
typedef unsigned int size_type;
class nonassignable { protected: nonassignable() {} ~nonassignable() {} };
template<class E> class ublas_expression : private nonassignable { protected: ublas_expression() {} ~ublas_expression() {} };
template<class E> class matrix_expression : public ublas_expression<E> { protected: matrix_expression() {} ~matrix_expression() {} };
template<class C> class matrix_container : public matrix_expression<C> { protected: matrix_container() {} ~matrix_container() {} };
template<class E> class storage_array : private nonassignable {};
template<class T, class ALLOC = std::allocator<T> >
class unbounded_array : public storage_array<unbounded_array<T, ALLOC> > {
public:
    explicit unbounded_array(size_type size, const ALLOC& a = ALLOC());
    ~unbounded_array();
    ALLOC alloc_; size_type size_; T* data_;
};
struct row_major { static size_type storage_size(size_type size1, size_type size2) { return size1 * size2; } };
template<class T, class L = row_major, class A = unbounded_array<T> >
class matrix : public matrix_container<matrix<T, L, A> > {
public:
    matrix(size_type size1, size_type size2)
        : matrix_container<matrix<T, L, A> >(), size1_(size1), size2_(size2), data_(L::storage_size(size1, size2)) {}
    size_type size1_; size_type size2_; A data_;
};
template class matrix<double>;
}}}
