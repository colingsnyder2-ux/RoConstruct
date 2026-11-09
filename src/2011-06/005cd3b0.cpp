// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cd3b0 { void reg(void*); };
extern Obj_005cd3b0 g_obj_005cd3b0;
extern void* g_arg_005cd3b0;
extern void cb_005cd3b0();
extern void tail_005cd3b0(void*);
extern void* __stdcall make_005cd3b0(void*, int);
struct X_005cd3b0 { X_005cd3b0(); };
X_005cd3b0::X_005cd3b0() { void* p=make_005cd3b0(g_arg_005cd3b0,27); g_obj_005cd3b0.reg(p); tail_005cd3b0((void*)&cb_005cd3b0); }
X_005cd3b0* func_005cd3b0() { static X_005cd3b0 x; return &x; }
