// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cca80 { void reg(void*); };
extern Obj_005cca80 g_obj_005cca80;
extern void* g_arg_005cca80;
extern void cb_005cca80();
extern void tail_005cca80(void*);
extern void* __stdcall make_005cca80(void*, int);
struct X_005cca80 { X_005cca80(); };
X_005cca80::X_005cca80() { void* p=make_005cca80(g_arg_005cca80,27); g_obj_005cca80.reg(p); tail_005cca80((void*)&cb_005cca80); }
X_005cca80* func_005cca80() { static X_005cca80 x; return &x; }
