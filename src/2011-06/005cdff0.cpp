// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cdff0 { void reg(void*); };
extern Obj_005cdff0 g_obj_005cdff0;
extern void* g_arg_005cdff0;
extern void cb_005cdff0();
extern void tail_005cdff0(void*);
extern void* __stdcall make_005cdff0(void*, int);
struct X_005cdff0 { X_005cdff0(); };
X_005cdff0::X_005cdff0() { void* p=make_005cdff0(g_arg_005cdff0,27); g_obj_005cdff0.reg(p); tail_005cdff0((void*)&cb_005cdff0); }
X_005cdff0* func_005cdff0() { static X_005cdff0 x; return &x; }
