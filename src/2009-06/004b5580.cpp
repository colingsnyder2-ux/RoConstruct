// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void weak_add_ref() { _InterlockedIncrement(&weak_count_); }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};

class weak_count {
public:
    sp_counted_base* pi_;
    weak_count(const weak_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->weak_add_ref(); }
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};

template<class T> class weak_ptr {
public:
    T* px;
    weak_count pn;
};

template<int I> struct arg {};

template<class T> class value {
public:
    value(T const& t) : t_(t) {}
private:
    T t_;
};

template<class A1> struct storage1 {
    explicit storage1(A1 a1) : a1_(a1) {}
    A1 a1_;
};
template<int I> struct storage1<arg<I> > {
    explicit storage1(arg<I>) {}
};
template<class A1, class A2> struct storage2 : public storage1<A1> {
    storage2(A1 a1, A2 a2) : storage1<A1>(a1), a2_(a2) {}
    A2 a2_;
};
template<class A1, int I> struct storage2<A1, arg<I> > : public storage1<A1> {
    storage2(A1 a1, arg<I>) : storage1<A1>(a1) {}
};
template<class A1, class A2, class A3> struct storage3 : public storage2<A1, A2> {
    storage3(A1 a1, A2 a2, A3 a3) : storage2<A1, A2>(a1, a2), a3_(a3) {}
    A3 a3_;
};
template<class A1, class A2, class A3, class A4> struct storage4 : public storage3<A1, A2, A3> {
    storage4(A1 a1, A2 a2, A3 a3, A4 a4) : storage3<A1, A2, A3>(a1, a2, a3), a4_(a4) {}
    A4 a4_;
};
template<class A1, class A2, class A3, class A4> class list4 : private storage4<A1, A2, A3, A4> {
    typedef storage4<A1, A2, A3, A4> base_type;
public:
    list4(A1 a1, A2 a2, A3 a3, A4 a4) : base_type(a1, a2, a3, a4) {}
};

struct A; struct B;
template class list4<arg<1>, arg<2>, value<weak_ptr<A> >, value<weak_ptr<B> > >;
