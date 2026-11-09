// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cf020 { void reg(void*); };
extern Obj_005cf020 g_obj_005cf020;
extern void* g_arg_005cf020;
extern void cb_005cf020();
extern void tail_005cf020(void*);
extern void* __stdcall make_005cf020(void*, int);
struct X_005cf020 { X_005cf020(); };
X_005cf020::X_005cf020() { void* p=make_005cf020(g_arg_005cf020,27); g_obj_005cf020.reg(p); tail_005cf020((void*)&cb_005cf020); }
X_005cf020* func_005cf020() { static X_005cf020 x; return &x; }
