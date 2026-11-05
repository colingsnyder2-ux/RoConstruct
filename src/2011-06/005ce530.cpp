// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ce530 { void reg(void*); };
extern Obj_005ce530 g_obj_005ce530;
extern void* g_arg_005ce530;
extern void cb_005ce530();
extern void tail_005ce530(void*);
extern void* __stdcall make_005ce530(void*, int);
struct X_005ce530 { X_005ce530(); };
X_005ce530::X_005ce530() { void* p=make_005ce530(g_arg_005ce530,27); g_obj_005ce530.reg(p); tail_005ce530((void*)&cb_005ce530); }
X_005ce530* func_005ce530() { static X_005ce530 x; return &x; }
