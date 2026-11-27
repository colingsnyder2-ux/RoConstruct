// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct C;
struct Reg { int x; void add(C**); };
Reg gReg;
struct B { virtual ~B(); };
struct C { virtual void v(); ~C(); };
C::~C(){ C* p = this; gReg.add(&p); }
