// from server: 58% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
namespace boost {
namespace _bi {
template<class T> class value {
public:
	value(T const & t): t_(t) {}
private:
	T t_;
};
template<class A1> struct storage1 {
	explicit storage1(A1 a1): a1_(a1) {}
	A1 a1_;
};
template<class A1, class A2> struct storage2: public storage1<A1> {
	typedef storage1<A1> inherited;
	storage2(A1 a1, A2 a2): storage1<A1>(a1), a2_(a2) {}
	A2 a2_;
};
template<class A1, class A2> class list2: private storage2<A1, A2> {
private:
	typedef storage2<A1, A2> base_type;
public:
	list2(A1 a1, A2 a2): base_type(a1, a2) {}
};
template<class R, class F, class L> class bind_t {
public:
	bind_t(F f, L const & l): f_(f), l_(l) {}
private:
	F f_;
	L l_;
};
template<class A1, class A2> struct list_av_2 {
	typedef list2<value<A1>, value<A2> > type;
};
}
template<class R, class B1, class B2, class A1, class A2>
_bi::bind_t<R, R (*) (B1, B2), typename _bi::list_av_2<A1, A2>::type>
bind(R (*f) (B1, B2), A1 a1, A2 a2)
{
	typedef R (*F) (B1, B2);
	typedef typename _bi::list_av_2<A1, A2>::type list_type;
	return _bi::bind_t<R, F, list_type> (f, list_type(a1, a2));
}
}
struct Ctx;
struct Arg;
void worker(Ctx*, Arg*);
template boost::_bi::bind_t<void, void(*)(Ctx*, Arg*), boost::_bi::list_av_2<Ctx*, Arg*>::type> boost::bind(void(*)(Ctx*, Arg*), Ctx*, Arg*);
