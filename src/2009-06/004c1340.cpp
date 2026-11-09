// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct X { X(const X&); ~X(); char d[0x2c]; };
template<class T> struct value { T t_; };
template<class A1, class A2> struct list2 { A1 a1_; A2 a2_; };
template<class R, class F, class L> struct bind_t { F f_; L l_; };
struct function_base {
	void* vtable;
	union { __declspec(align(8)) char buf[0x18]; } functor;
	function_base() : vtable(0) {}
};
template<class R> struct function0 : function_base {
	template<class F> function0(F f, int = 0) : function_base() { this->assign_to(f); }
	template<class F> void assign_to(F f);
};
typedef bind_t<void, void (*)(X, bool), list2<value<X>, value<bool> > > B;
template function0<void>::function0(B, int);
