// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
struct Q { void g(); };
struct W { char pad[0xd0]; Q* q; };
struct T { char pad[0x38]; W* w; int f(int,int,int,int,int); };
int T::f(int a,int b,int c,int d,int e){ W* x = w; if (x->q) x->q->g(); return c == 1; }
