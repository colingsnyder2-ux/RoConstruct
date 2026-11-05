// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005caf60 { void reg(void*); };
extern Obj_005caf60 g_obj_005caf60;
extern void* g_arg_005caf60;
extern void cb_005caf60();
extern void tail_005caf60(void*);
extern void* __stdcall make_005caf60(void*, int);
struct X_005caf60 { X_005caf60(); };
X_005caf60::X_005caf60() { void* p=make_005caf60(g_arg_005caf60,27); g_obj_005caf60.reg(p); tail_005caf60((void*)&cb_005caf60); }
X_005caf60* func_005caf60() { static X_005caf60 x; return &x; }
