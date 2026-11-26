// from server: 92% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V { int v; };
struct Base : virtual V { void call(int); };
struct Pad { char p[0x134]; };
struct Derived : Pad, Base { void call(int); };
struct Functionality { bool a; bool b; Functionality(bool a_, bool b_) { b = b_; a = a_; } };
struct Holder { Functionality f; int x; Holder() : f(true,false), x(0) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Desc { typedef void (Base::*Fn)(int);
  Desc(Fn fn, const char* a, const char* b, int z, Functionality fu, Sig s); 
  Desc(Fn fn, const char* a, const char* b, int z, Functionality fu, Desc* o); ~Desc(); char pad[0x40]; };
static Desc other(static_cast<Desc::Fn>(&Derived::call), "TakeDamage", "amount", 0, Functionality(false,false), Sig());
static Desc desc(static_cast<Desc::Fn>(&Derived::call), "takeDamage", "amount", 0, Holder().f, &other);
