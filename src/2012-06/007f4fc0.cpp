// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE
struct A{ char p[0x20]; float f20; char q[0x10]; int v; void f(int n){ if(n==v){ v=n; return;} v=n; if(n==0) f20=11.0f; } }; void k(A*a,int n){a->f(n);}
