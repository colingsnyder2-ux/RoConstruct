// from server: 100% by colin
// roc-flags: /O2 /GS /EHsc /MD
struct Derived { Derived(); char pad[0x1f0]; };
struct X { Derived* create(); };
Derived* X::create() { Derived* p = new Derived(); return p; }
