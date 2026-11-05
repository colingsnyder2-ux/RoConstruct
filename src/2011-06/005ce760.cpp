// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ce760 { void reg(void*); };
extern Obj_005ce760 g_obj_005ce760;
extern void* g_arg_005ce760;
extern void cb_005ce760();
extern void tail_005ce760(void*);
extern void* __stdcall make_005ce760(void*, int);
struct X_005ce760 { X_005ce760(); };
X_005ce760::X_005ce760() { void* p=make_005ce760(g_arg_005ce760,27); g_obj_005ce760.reg(p); tail_005ce760((void*)&cb_005ce760); }
X_005ce760* func_005ce760() { static X_005ce760 x; return &x; }
