// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE
struct B{ char p[0xcc]; float v; }; struct S{ char p[0xa8]; B* b; void f(float a); }; void S::f(float a){ b->v=a; }
