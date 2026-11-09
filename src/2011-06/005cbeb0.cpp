// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cbeb0 { void reg(void*); };
extern Obj_005cbeb0 g_obj_005cbeb0;
extern void* g_arg_005cbeb0;
extern void cb_005cbeb0();
extern void tail_005cbeb0(void*);
extern void* __stdcall make_005cbeb0(void*, int);
struct X_005cbeb0 { X_005cbeb0(); };
X_005cbeb0::X_005cbeb0() { void* p=make_005cbeb0(g_arg_005cbeb0,27); g_obj_005cbeb0.reg(p); tail_005cbeb0((void*)&cb_005cbeb0); }
X_005cbeb0* func_005cbeb0() { static X_005cbeb0 x; return &x; }
