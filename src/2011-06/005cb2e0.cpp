// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb2e0 { void reg(void*); };
extern Obj_005cb2e0 g_obj_005cb2e0;
extern void* g_arg_005cb2e0;
extern void cb_005cb2e0();
extern void tail_005cb2e0(void*);
extern void* __stdcall make_005cb2e0(void*, int);
struct X_005cb2e0 { X_005cb2e0(); };
X_005cb2e0::X_005cb2e0() { void* p=make_005cb2e0(g_arg_005cb2e0,3); g_obj_005cb2e0.reg(p); tail_005cb2e0((void*)&cb_005cb2e0); }
X_005cb2e0* func_005cb2e0() { static X_005cb2e0 x; return &x; }
