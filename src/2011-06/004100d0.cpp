// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_004100d0 { void reg(void*); };
extern Obj_004100d0 g_obj_004100d0;
extern void* g_arg_004100d0;
extern void cb_004100d0();
extern void tail_004100d0(void*);
extern void* __stdcall make_004100d0(void*, int);
struct X_004100d0 { X_004100d0(); };
X_004100d0::X_004100d0() { void* p=make_004100d0(g_arg_004100d0,27); g_obj_004100d0.reg(p); tail_004100d0((void*)&cb_004100d0); }
X_004100d0* func_004100d0() { static X_004100d0 x; return &x; }
