// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cba50 { void reg(void*); };
extern Obj_005cba50 g_obj_005cba50;
extern void* g_arg_005cba50;
extern void cb_005cba50();
extern void tail_005cba50(void*);
extern void* __stdcall make_005cba50(void*, int);
struct X_005cba50 { X_005cba50(); };
X_005cba50::X_005cba50() { void* p=make_005cba50(g_arg_005cba50,27); g_obj_005cba50.reg(p); tail_005cba50((void*)&cb_005cba50); }
X_005cba50* func_005cba50() { static X_005cba50 x; return &x; }
