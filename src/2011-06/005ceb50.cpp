// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ceb50 { void reg(void*); };
extern Obj_005ceb50 g_obj_005ceb50;
extern void* g_arg_005ceb50;
extern void cb_005ceb50();
extern void tail_005ceb50(void*);
extern void* __stdcall make_005ceb50(void*, int);
struct X_005ceb50 { X_005ceb50(); };
X_005ceb50::X_005ceb50() { void* p=make_005ceb50(g_arg_005ceb50,27); g_obj_005ceb50.reg(p); tail_005ceb50((void*)&cb_005ceb50); }
X_005ceb50* func_005ceb50() { static X_005ceb50 x; return &x; }
