// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct X { X(); char d[0x14]; };
struct shared_count {
	void* pi_;
	template<class Y> explicit shared_count(Y* p);
};
template<class T> struct esft {};
template<class T, class Y> void sp_enable_shared_from_this(const shared_count& pn, const esft<T>* pe, const Y* px);
struct XB : esft<X> {};
template<class T> class shared_ptr {
public:
	~shared_ptr();
	T* px;
	shared_count pn;
	template<class Y> explicit shared_ptr(Y* p) : px(p), pn(p) { sp_enable_shared_from_this(pn, p, p); }
};
void sp_enable_shared_from_this(const shared_count& pn, ...);
shared_ptr<X> make() { return shared_ptr<X>(new X()); }
