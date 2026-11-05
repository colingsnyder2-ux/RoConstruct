// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ce990 { void reg(void*); };
extern Obj_005ce990 g_obj_005ce990;
extern void* g_arg_005ce990;
extern void cb_005ce990();
extern void tail_005ce990(void*);
extern void* __stdcall make_005ce990(void*, int);
struct X_005ce990 { X_005ce990(); };
X_005ce990::X_005ce990() { void* p=make_005ce990(g_arg_005ce990,27); g_obj_005ce990.reg(p); tail_005ce990((void*)&cb_005ce990); }
X_005ce990* func_005ce990() { static X_005ce990 x; return &x; }
