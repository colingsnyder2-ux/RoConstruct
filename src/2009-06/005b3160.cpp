// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /GS- /EHsc /MD
namespace boost { namespace numeric { namespace ublas {
typedef unsigned int size_type;
template<class T>
class unbounded_array {
public:
    unbounded_array& operator=(const unbounded_array& a);
    int alloc_; size_type size_; T* data_;
};
template<class T, class A = unbounded_array<T> >
class vector {
public:
    typedef A array_type;
    const array_type& data() const { return data_; }
    array_type& data() { return data_; }
    vector& operator=(const vector& v) {
        data() = v.data();
        return *this;
    }
    array_type data_;
};
template vector<double>& vector<double>::operator=(const vector<double>&);
}}}
