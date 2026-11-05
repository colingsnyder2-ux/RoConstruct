// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cbac0 { void reg(void*); };
extern Obj_005cbac0 g_obj_005cbac0;
extern void* g_arg_005cbac0;
extern void cb_005cbac0();
extern void tail_005cbac0(void*);
extern void* __stdcall make_005cbac0(void*, int);
struct X_005cbac0 { X_005cbac0(); };
X_005cbac0::X_005cbac0() { void* p=make_005cbac0(g_arg_005cbac0,27); g_obj_005cbac0.reg(p); tail_005cbac0((void*)&cb_005cbac0); }
X_005cbac0* func_005cbac0() { static X_005cbac0 x; return &x; }
