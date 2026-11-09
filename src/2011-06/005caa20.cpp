// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005caa20 { void reg(void*); };
extern Obj_005caa20 g_obj_005caa20;
extern void* g_arg_005caa20;
extern void cb_005caa20();
extern void tail_005caa20(void*);
extern void* __stdcall make_005caa20(void*, int);
struct X_005caa20 { X_005caa20(); };
X_005caa20::X_005caa20() { void* p=make_005caa20(g_arg_005caa20,27); g_obj_005caa20.reg(p); tail_005caa20((void*)&cb_005caa20); }
X_005caa20* func_005caa20() { static X_005caa20 x; return &x; }
