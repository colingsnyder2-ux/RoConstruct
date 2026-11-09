// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cf330 { void reg(void*); };
extern Obj_005cf330 g_obj_005cf330;
extern void* g_arg_005cf330;
extern void cb_005cf330();
extern void tail_005cf330(void*);
extern void* __stdcall make_005cf330(void*, int);
struct X_005cf330 { X_005cf330(); };
X_005cf330::X_005cf330() { void* p=make_005cf330(g_arg_005cf330,27); g_obj_005cf330.reg(p); tail_005cf330((void*)&cb_005cf330); }
X_005cf330* func_005cf330() { static X_005cf330 x; return &x; }
