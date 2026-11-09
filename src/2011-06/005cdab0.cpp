// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cdab0 { void reg(void*); };
extern Obj_005cdab0 g_obj_005cdab0;
extern void* g_arg_005cdab0;
extern void cb_005cdab0();
extern void tail_005cdab0(void*);
extern void* __stdcall make_005cdab0(void*, int);
struct X_005cdab0 { X_005cdab0(); };
X_005cdab0::X_005cdab0() { void* p=make_005cdab0(g_arg_005cdab0,27); g_obj_005cdab0.reg(p); tail_005cdab0((void*)&cb_005cdab0); }
X_005cdab0* func_005cdab0() { static X_005cdab0 x; return &x; }
