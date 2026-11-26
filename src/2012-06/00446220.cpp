// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Ex { char b[44]; Ex(int); };
struct TI { int a, b, c, d; };
extern TI ti;
__declspec(noreturn) void __stdcall thr(void*, const TI*);
struct R { int u; int f4; void f(); };
void R::f() { Ex e(f4); thr(&e, &ti); }