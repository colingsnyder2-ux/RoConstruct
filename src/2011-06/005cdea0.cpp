// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cdea0 { void reg(void*); };
extern Obj_005cdea0 g_obj_005cdea0;
extern void* g_arg_005cdea0;
extern void cb_005cdea0();
extern void tail_005cdea0(void*);
extern void* __stdcall make_005cdea0(void*, int);
struct X_005cdea0 { X_005cdea0(); };
X_005cdea0::X_005cdea0() { void* p=make_005cdea0(g_arg_005cdea0,27); g_obj_005cdea0.reg(p); tail_005cdea0((void*)&cb_005cdea0); }
X_005cdea0* func_005cdea0() { static X_005cdea0 x; return &x; }
