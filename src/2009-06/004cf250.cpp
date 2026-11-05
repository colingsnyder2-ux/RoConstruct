// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /EHsc /MD
struct X { int a, b, c; };
struct T;
void intrusive_ptr_add_ref(T* p);
template<class U> class intrusive_ptr {
	U* px;
public:
	intrusive_ptr(U* p, bool add_ref = true) : px(p) { if (px != 0 && add_ref) intrusive_ptr_add_ref(px); }
	~intrusive_ptr();
};
T* create(const X& x);
intrusive_ptr<T> make(X x) { return intrusive_ptr<T>(create(x)); }
