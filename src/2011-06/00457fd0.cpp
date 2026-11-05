// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_00457fd0 { void reg(void*); };
extern Obj_00457fd0 g_obj_00457fd0;
extern void* g_arg_00457fd0;
extern void cb_00457fd0();
extern void tail_00457fd0(void*);
extern void* __stdcall make_00457fd0(void*, int);
struct X_00457fd0 { X_00457fd0(); };
X_00457fd0::X_00457fd0() { void* p=make_00457fd0(g_arg_00457fd0,27); g_obj_00457fd0.reg(p); tail_00457fd0((void*)&cb_00457fd0); }
X_00457fd0* func_00457fd0() { static X_00457fd0 x; return &x; }
