// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE
struct P { char pad[0x111]; bool f; };
struct Q { char pad[0x20]; P* p; };
struct R { int x; Q* q; };
R* getR();
struct S { char pad[0x10]; double m; double now(); bool f(); };
bool S::f() { double t = now(); if (m + 10.0 > t) return false; P* p = getR()->q->p; return p->f == false; }
