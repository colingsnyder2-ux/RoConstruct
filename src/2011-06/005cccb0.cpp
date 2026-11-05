// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cccb0 { void reg(void*); };
extern Obj_005cccb0 g_obj_005cccb0;
extern void* g_arg_005cccb0;
extern void cb_005cccb0();
extern void tail_005cccb0(void*);
extern void* __stdcall make_005cccb0(void*, int);
struct X_005cccb0 { X_005cccb0(); };
X_005cccb0::X_005cccb0() { void* p=make_005cccb0(g_arg_005cccb0,27); g_obj_005cccb0.reg(p); tail_005cccb0((void*)&cb_005cccb0); }
X_005cccb0* func_005cccb0() { static X_005cccb0 x; return &x; }
