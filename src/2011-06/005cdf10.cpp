// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cdf10 { void reg(void*); };
extern Obj_005cdf10 g_obj_005cdf10;
extern void* g_arg_005cdf10;
extern void cb_005cdf10();
extern void tail_005cdf10(void*);
extern void* __stdcall make_005cdf10(void*, int);
struct X_005cdf10 { X_005cdf10(); };
X_005cdf10::X_005cdf10() { void* p=make_005cdf10(g_arg_005cdf10,27); g_obj_005cdf10.reg(p); tail_005cdf10((void*)&cb_005cdf10); }
X_005cdf10* func_005cdf10() { static X_005cdf10 x; return &x; }
