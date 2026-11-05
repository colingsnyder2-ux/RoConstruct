// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ccee0 { void reg(void*); };
extern Obj_005ccee0 g_obj_005ccee0;
extern void* g_arg_005ccee0;
extern void cb_005ccee0();
extern void tail_005ccee0(void*);
extern void* __stdcall make_005ccee0(void*, int);
struct X_005ccee0 { X_005ccee0(); };
X_005ccee0::X_005ccee0() { void* p=make_005ccee0(g_arg_005ccee0,27); g_obj_005ccee0.reg(p); tail_005ccee0((void*)&cb_005ccee0); }
X_005ccee0* func_005ccee0() { static X_005ccee0 x; return &x; }
