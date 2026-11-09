// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cdce0 { void reg(void*); };
extern Obj_005cdce0 g_obj_005cdce0;
extern void* g_arg_005cdce0;
extern void cb_005cdce0();
extern void tail_005cdce0(void*);
extern void* __stdcall make_005cdce0(void*, int);
struct X_005cdce0 { X_005cdce0(); };
X_005cdce0::X_005cdce0() { void* p=make_005cdce0(g_arg_005cdce0,27); g_obj_005cdce0.reg(p); tail_005cdce0((void*)&cb_005cdce0); }
X_005cdce0* func_005cdce0() { static X_005cdce0 x; return &x; }
