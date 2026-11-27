// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct B { unsigned q(); }; struct A { B* a(); }; struct C { char pad[0x14]; A a; bool f(); int g(); };

bool C::f(){ return a.a()->q() > 0; }
