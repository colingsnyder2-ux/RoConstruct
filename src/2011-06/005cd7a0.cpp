// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cd7a0 { void reg(void*); };
extern Obj_005cd7a0 g_obj_005cd7a0;
extern void* g_arg_005cd7a0;
extern void cb_005cd7a0();
extern void tail_005cd7a0(void*);
extern void* __stdcall make_005cd7a0(void*, int);
struct X_005cd7a0 { X_005cd7a0(); };
X_005cd7a0::X_005cd7a0() { void* p=make_005cd7a0(g_arg_005cd7a0,27); g_obj_005cd7a0.reg(p); tail_005cd7a0((void*)&cb_005cd7a0); }
X_005cd7a0* func_005cd7a0() { static X_005cd7a0 x; return &x; }
