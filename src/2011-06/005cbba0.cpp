// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cbba0 { void reg(void*); };
extern Obj_005cbba0 g_obj_005cbba0;
extern void* g_arg_005cbba0;
extern void cb_005cbba0();
extern void tail_005cbba0(void*);
extern void* __stdcall make_005cbba0(void*, int);
struct X_005cbba0 { X_005cbba0(); };
X_005cbba0::X_005cbba0() { void* p=make_005cbba0(g_arg_005cbba0,27); g_obj_005cbba0.reg(p); tail_005cbba0((void*)&cb_005cbba0); }
X_005cbba0* func_005cbba0() { static X_005cbba0 x; return &x; }
