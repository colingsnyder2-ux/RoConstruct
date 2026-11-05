// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cd030 { void reg(void*); };
extern Obj_005cd030 g_obj_005cd030;
extern void* g_arg_005cd030;
extern void cb_005cd030();
extern void tail_005cd030(void*);
extern void* __stdcall make_005cd030(void*, int);
struct X_005cd030 { X_005cd030(); };
X_005cd030::X_005cd030() { void* p=make_005cd030(g_arg_005cd030,27); g_obj_005cd030.reg(p); tail_005cd030((void*)&cb_005cd030); }
X_005cd030* func_005cd030() { static X_005cd030 x; return &x; }
