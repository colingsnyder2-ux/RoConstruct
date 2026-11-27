// from server: 94% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct A { virtual void f(); int data[2]; };
struct E { virtual void g(); int data[4]; };
struct inj : A, E { inj(inj const& x); };
struct cb { virtual void clone() const; virtual void rethrow() const; };
struct impl : inj, cb { impl(impl const& x); virtual void clone() const; virtual void rethrow() const; };
impl::impl(impl const& x) : inj(x), cb() {}
void impl::rethrow() const { throw *this; }
