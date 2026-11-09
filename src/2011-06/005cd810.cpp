// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cd810 { void reg(void*); };
extern Obj_005cd810 g_obj_005cd810;
extern void* g_arg_005cd810;
extern void cb_005cd810();
extern void tail_005cd810(void*);
extern void* __stdcall make_005cd810(void*, int);
struct X_005cd810 { X_005cd810(); };
X_005cd810::X_005cd810() { void* p=make_005cd810(g_arg_005cd810,27); g_obj_005cd810.reg(p); tail_005cd810((void*)&cb_005cd810); }
X_005cd810* func_005cd810() { static X_005cd810 x; return &x; }
