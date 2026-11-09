// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cbf20 { void reg(void*); };
extern Obj_005cbf20 g_obj_005cbf20;
extern void* g_arg_005cbf20;
extern void cb_005cbf20();
extern void tail_005cbf20(void*);
extern void* __stdcall make_005cbf20(void*, int);
struct X_005cbf20 { X_005cbf20(); };
X_005cbf20::X_005cbf20() { void* p=make_005cbf20(g_arg_005cbf20,27); g_obj_005cbf20.reg(p); tail_005cbf20((void*)&cb_005cbf20); }
X_005cbf20* func_005cbf20() { static X_005cbf20 x; return &x; }
