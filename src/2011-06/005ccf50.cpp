// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ccf50 { void reg(void*); };
extern Obj_005ccf50 g_obj_005ccf50;
extern void* g_arg_005ccf50;
extern void cb_005ccf50();
extern void tail_005ccf50(void*);
extern void* __stdcall make_005ccf50(void*, int);
struct X_005ccf50 { X_005ccf50(); };
X_005ccf50::X_005ccf50() { void* p=make_005ccf50(g_arg_005ccf50,3); g_obj_005ccf50.reg(p); tail_005ccf50((void*)&cb_005ccf50); }
X_005ccf50* func_005ccf50() { static X_005ccf50 x; return &x; }
