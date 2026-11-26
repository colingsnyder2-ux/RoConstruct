// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B { bool g(); };
struct A { int a,b,c; B* p; bool f(); };
bool A::f(){ return !p->g(); }
