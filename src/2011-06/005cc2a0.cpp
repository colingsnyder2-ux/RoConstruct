// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc2a0 { void reg(void*); };
extern Obj_005cc2a0 g_obj_005cc2a0;
extern void* g_arg_005cc2a0;
extern void cb_005cc2a0();
extern void tail_005cc2a0(void*);
extern void* __stdcall make_005cc2a0(void*, int);
struct X_005cc2a0 { X_005cc2a0(); };
X_005cc2a0::X_005cc2a0() { void* p=make_005cc2a0(g_arg_005cc2a0,27); g_obj_005cc2a0.reg(p); tail_005cc2a0((void*)&cb_005cc2a0); }
X_005cc2a0* func_005cc2a0() { static X_005cc2a0 x; return &x; }
