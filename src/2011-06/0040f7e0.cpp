// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_0040f7e0 { void reg(void*); };
extern Obj_0040f7e0 g_obj_0040f7e0;
extern void* g_arg_0040f7e0;
extern void cb_0040f7e0();
extern void tail_0040f7e0(void*);
extern void* __stdcall make_0040f7e0(void*, int);
struct X_0040f7e0 { X_0040f7e0(); };
X_0040f7e0::X_0040f7e0() { void* p=make_0040f7e0(g_arg_0040f7e0,27); g_obj_0040f7e0.reg(p); tail_0040f7e0((void*)&cb_0040f7e0); }
X_0040f7e0* func_0040f7e0() { static X_0040f7e0 x; return &x; }
