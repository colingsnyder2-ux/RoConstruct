// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cddc0 { void reg(void*); };
extern Obj_005cddc0 g_obj_005cddc0;
extern void* g_arg_005cddc0;
extern void cb_005cddc0();
extern void tail_005cddc0(void*);
extern void* __stdcall make_005cddc0(void*, int);
struct X_005cddc0 { X_005cddc0(); };
X_005cddc0::X_005cddc0() { void* p=make_005cddc0(g_arg_005cddc0,27); g_obj_005cddc0.reg(p); tail_005cddc0((void*)&cb_005cddc0); }
X_005cddc0* func_005cddc0() { static X_005cddc0 x; return &x; }
