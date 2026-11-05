// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cdf80 { void reg(void*); };
extern Obj_005cdf80 g_obj_005cdf80;
extern void* g_arg_005cdf80;
extern void cb_005cdf80();
extern void tail_005cdf80(void*);
extern void* __stdcall make_005cdf80(void*, int);
struct X_005cdf80 { X_005cdf80(); };
X_005cdf80::X_005cdf80() { void* p=make_005cdf80(g_arg_005cdf80,27); g_obj_005cdf80.reg(p); tail_005cdf80((void*)&cb_005cdf80); }
X_005cdf80* func_005cdf80() { static X_005cdf80 x; return &x; }
