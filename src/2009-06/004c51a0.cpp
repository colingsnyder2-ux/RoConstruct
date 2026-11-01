// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Plugin {
	Plugin(const Plugin&);
	~Plugin();
	char data[0x48];
};
template<int I> struct arg {};
template<class A1> struct storage1 { A1 a1_; storage1(A1 a1) : a1_(a1) {} };
template<int I> struct storage1<arg<I> > { storage1(arg<I>) {} };
template<class A1, class A2> struct storage2 : storage1<A1> {
	storage2(A1 a1, A2 a2) : storage1<A1>(a1), a2_(a2) {}
	A2 a2_;
};
template<class A1, class A2> struct list2 : storage2<A1, A2> {
	list2(A1 a1, A2 a2);
};
template<class A1, class A2> list2<A1, A2>::list2(A1 a1, A2 a2) : storage2<A1, A2>(a1, a2) {}
template struct list2<arg<1>, Plugin>;
