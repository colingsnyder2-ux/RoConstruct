// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ccfc0 { void reg(void*); };
extern Obj_005ccfc0 g_obj_005ccfc0;
extern void* g_arg_005ccfc0;
extern void cb_005ccfc0();
extern void tail_005ccfc0(void*);
extern void* __stdcall make_005ccfc0(void*, int);
struct X_005ccfc0 { X_005ccfc0(); };
X_005ccfc0::X_005ccfc0() { void* p=make_005ccfc0(g_arg_005ccfc0,27); g_obj_005ccfc0.reg(p); tail_005ccfc0((void*)&cb_005ccfc0); }
X_005ccfc0* func_005ccfc0() { static X_005ccfc0 x; return &x; }
