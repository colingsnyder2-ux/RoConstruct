// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ void g(); }; struct A{ char p[0x36c]; void f(int); B* me(); };
void A::f(int){ ((B*)((char*)this-0x36c))->g(); }
