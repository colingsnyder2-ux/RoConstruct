// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc8c0 { void reg(void*); };
extern Obj_005cc8c0 g_obj_005cc8c0;
extern void* g_arg_005cc8c0;
extern void cb_005cc8c0();
extern void tail_005cc8c0(void*);
extern void* __stdcall make_005cc8c0(void*, int);
struct X_005cc8c0 { X_005cc8c0(); };
X_005cc8c0::X_005cc8c0() { void* p=make_005cc8c0(g_arg_005cc8c0,27); g_obj_005cc8c0.reg(p); tail_005cc8c0((void*)&cb_005cc8c0); }
X_005cc8c0* func_005cc8c0() { static X_005cc8c0 x; return &x; }
