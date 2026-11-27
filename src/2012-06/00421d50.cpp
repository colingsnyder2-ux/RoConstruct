// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
int __stdcall g(int,int,int,int);
struct A { char pad[0x58]; int a; int b; int f(); };
int A::f(){ return g(a, b, 10000, 0); }
