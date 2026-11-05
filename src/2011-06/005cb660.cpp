// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb660 { void reg(void*); };
extern Obj_005cb660 g_obj_005cb660;
extern void* g_arg_005cb660;
extern void cb_005cb660();
extern void tail_005cb660(void*);
extern void* __stdcall make_005cb660(void*, int);
struct X_005cb660 { X_005cb660(); };
X_005cb660::X_005cb660() { void* p=make_005cb660(g_arg_005cb660,27); g_obj_005cb660.reg(p); tail_005cb660((void*)&cb_005cb660); }
X_005cb660* func_005cb660() { static X_005cb660 x; return &x; }
