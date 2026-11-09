// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ccd20 { void reg(void*); };
extern Obj_005ccd20 g_obj_005ccd20;
extern void* g_arg_005ccd20;
extern void cb_005ccd20();
extern void tail_005ccd20(void*);
extern void* __stdcall make_005ccd20(void*, int);
struct X_005ccd20 { X_005ccd20(); };
X_005ccd20::X_005ccd20() { void* p=make_005ccd20(g_arg_005ccd20,27); g_obj_005ccd20.reg(p); tail_005ccd20((void*)&cb_005ccd20); }
X_005ccd20* func_005ccd20() { static X_005ccd20 x; return &x; }
