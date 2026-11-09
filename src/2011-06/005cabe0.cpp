// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cabe0 { void reg(void*); };
extern Obj_005cabe0 g_obj_005cabe0;
extern void* g_arg_005cabe0;
extern void cb_005cabe0();
extern void tail_005cabe0(void*);
extern void* __stdcall make_005cabe0(void*, int);
struct X_005cabe0 { X_005cabe0(); };
X_005cabe0::X_005cabe0() { void* p=make_005cabe0(g_arg_005cabe0,27); g_obj_005cabe0.reg(p); tail_005cabe0((void*)&cb_005cabe0); }
X_005cabe0* func_005cabe0() { static X_005cabe0 x; return &x; }
