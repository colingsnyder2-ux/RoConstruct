// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cafd0 { void reg(void*); };
extern Obj_005cafd0 g_obj_005cafd0;
extern void* g_arg_005cafd0;
extern void cb_005cafd0();
extern void tail_005cafd0(void*);
extern void* __stdcall make_005cafd0(void*, int);
struct X_005cafd0 { X_005cafd0(); };
X_005cafd0::X_005cafd0() { void* p=make_005cafd0(g_arg_005cafd0,27); g_obj_005cafd0.reg(p); tail_005cafd0((void*)&cb_005cafd0); }
X_005cafd0* func_005cafd0() { static X_005cafd0 x; return &x; }
