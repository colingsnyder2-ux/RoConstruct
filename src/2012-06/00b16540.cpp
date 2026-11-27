// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE
struct E { int a, b; };
extern void __cdecl fr(void*);
struct Q { E* b; E* e; E* c; int pad; unsigned n;
 ~Q() { for (unsigned i = 0; i < n; ++i) { ++c; c = (c == e) ? b : c; } if (b) fr(b); } };
static Q g;
