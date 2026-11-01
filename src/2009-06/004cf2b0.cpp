// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /EHsc /MD
template<class T> struct type {};
template<class T> class value { public: value(T const& t) : t_(t) {} T& get() { return t_; } private: T t_; };
class list0 { public: list0(); template<class T> T& operator[](value<T>& v) const { return v.get(); } };
template<class A1, class A2> struct storage2 { A1 a1_; A2 a2_; };
template<class A1, class A2> class list2 : private storage2<A1, A2> {
public:
    typedef storage2<A1, A2> base_type;
    template<class F, class A> void operator()(type<void>, F& f, A& a, int)
    {
        f(a[base_type::a1_], a[base_type::a2_]);
    }
};
template<class R, class T, class A1> class mf1 {
    typedef R (T::*F)(A1);
    F f_;
public:
    R operator()(T* p, A1 a1) const { return (p->*f_)(a1); }
};
template<class R, class F, class L> class bind_t {
    F f_;
    L l_;
public:
    void operator()()
    {
        list0 a;
        l_(type<void>(), f_, a, 0);
    }
};
struct Target { void run(int); };
template class bind_t<void, mf1<void, Target, int>, list2<value<Target*>, value<int> > >;
