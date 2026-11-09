// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ccaf0 { void reg(void*); };
extern Obj_005ccaf0 g_obj_005ccaf0;
extern void* g_arg_005ccaf0;
extern void cb_005ccaf0();
extern void tail_005ccaf0(void*);
extern void* __stdcall make_005ccaf0(void*, int);
struct X_005ccaf0 { X_005ccaf0(); };
X_005ccaf0::X_005ccaf0() { void* p=make_005ccaf0(g_arg_005ccaf0,27); g_obj_005ccaf0.reg(p); tail_005ccaf0((void*)&cb_005ccaf0); }
X_005ccaf0* func_005ccaf0() { static X_005ccaf0 x; return &x; }
