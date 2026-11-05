// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cd180 { void reg(void*); };
extern Obj_005cd180 g_obj_005cd180;
extern void* g_arg_005cd180;
extern void cb_005cd180();
extern void tail_005cd180(void*);
extern void* __stdcall make_005cd180(void*, int);
struct X_005cd180 { X_005cd180(); };
X_005cd180::X_005cd180() { void* p=make_005cd180(g_arg_005cd180,27); g_obj_005cd180.reg(p); tail_005cd180((void*)&cb_005cd180); }
X_005cd180* func_005cd180() { static X_005cd180 x; return &x; }
