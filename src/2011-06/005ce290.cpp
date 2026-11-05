// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ce290 { void reg(void*); };
extern Obj_005ce290 g_obj_005ce290;
extern void* g_arg_005ce290;
extern void cb_005ce290();
extern void tail_005ce290(void*);
extern void* __stdcall make_005ce290(void*, int);
struct X_005ce290 { X_005ce290(); };
X_005ce290::X_005ce290() { void* p=make_005ce290(g_arg_005ce290,27); g_obj_005ce290.reg(p); tail_005ce290((void*)&cb_005ce290); }
X_005ce290* func_005ce290() { static X_005ce290 x; return &x; }
