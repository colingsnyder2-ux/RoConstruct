// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb740 { void reg(void*); };
extern Obj_005cb740 g_obj_005cb740;
extern void* g_arg_005cb740;
extern void cb_005cb740();
extern void tail_005cb740(void*);
extern void* __stdcall make_005cb740(void*, int);
struct X_005cb740 { X_005cb740(); };
X_005cb740::X_005cb740() { void* p=make_005cb740(g_arg_005cb740,27); g_obj_005cb740.reg(p); tail_005cb740((void*)&cb_005cb740); }
X_005cb740* func_005cb740() { static X_005cb740 x; return &x; }
