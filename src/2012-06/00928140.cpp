// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
template<class R,class T,class A1> struct mf1{ typedef R (T::*F)(A1); F f_; explicit mf1(F f):f_(f){} };
template<class T> struct value{ T t_; value(T const& t):t_(t){} };
template<int I> struct arg{ arg(){} };
template<class A1,class A2> struct list2{ A1 a1_; list2(A1 a1, A2):a1_(a1){} };
template<class R,class F,class L> struct bind_t{ F f_; L l_; bind_t(F f, L const& l):f_(f),l_(l){} };
template<class R,class T,class B1,class A1,class A2> bind_t<R, mf1<R,T,B1>, list2<value<A1>,A2> > bind(R (T::*f)(B1), A1 a1, A2 a2){ typedef mf1<R,T,B1> F; typedef list2<value<A1>,A2> L; return bind_t<R,F,L>(F(f), L(a1,a2)); }
struct A; struct S{ void m(int); void f(A*); };
struct A{ void h(bind_t<void, mf1<void,S,int>, list2<value<S*>,arg<1> > > b); };
void S::f(A* a){ a->h(bind(&S::m, this, arg<1>())); }
