// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ccbd0 { void reg(void*); };
extern Obj_005ccbd0 g_obj_005ccbd0;
extern void* g_arg_005ccbd0;
extern void cb_005ccbd0();
extern void tail_005ccbd0(void*);
extern void* __stdcall make_005ccbd0(void*, int);
struct X_005ccbd0 { X_005ccbd0(); };
X_005ccbd0::X_005ccbd0() { void* p=make_005ccbd0(g_arg_005ccbd0,27); g_obj_005ccbd0.reg(p); tail_005ccbd0((void*)&cb_005ccbd0); }
X_005ccbd0* func_005ccbd0() { static X_005ccbd0 x; return &x; }
