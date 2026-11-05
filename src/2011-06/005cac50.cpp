// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cac50 { void reg(void*); };
extern Obj_005cac50 g_obj_005cac50;
extern void* g_arg_005cac50;
extern void cb_005cac50();
extern void tail_005cac50(void*);
extern void* __stdcall make_005cac50(void*, int);
struct X_005cac50 { X_005cac50(); };
X_005cac50::X_005cac50() { void* p=make_005cac50(g_arg_005cac50,27); g_obj_005cac50.reg(p); tail_005cac50((void*)&cb_005cac50); }
X_005cac50* func_005cac50() { static X_005cac50 x; return &x; }
