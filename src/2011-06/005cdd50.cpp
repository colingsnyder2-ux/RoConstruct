// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cdd50 { void reg(void*); };
extern Obj_005cdd50 g_obj_005cdd50;
extern void* g_arg_005cdd50;
extern void cb_005cdd50();
extern void tail_005cdd50(void*);
extern void* __stdcall make_005cdd50(void*, int);
struct X_005cdd50 { X_005cdd50(); };
X_005cdd50::X_005cdd50() { void* p=make_005cdd50(g_arg_005cdd50,27); g_obj_005cdd50.reg(p); tail_005cdd50((void*)&cb_005cdd50); }
X_005cdd50* func_005cdd50() { static X_005cdd50 x; return &x; }
