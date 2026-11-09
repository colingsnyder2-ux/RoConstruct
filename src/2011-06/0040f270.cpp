// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_0040f270 { void reg(void*); };
extern Obj_0040f270 g_obj_0040f270;
extern void* g_arg_0040f270;
extern void cb_0040f270();
extern void tail_0040f270(void*);
extern void* __stdcall make_0040f270(void*, int);
struct X_0040f270 { X_0040f270(); };
X_0040f270::X_0040f270() { void* p=make_0040f270(g_arg_0040f270,27); g_obj_0040f270.reg(p); tail_0040f270((void*)&cb_0040f270); }
X_0040f270* func_0040f270() { static X_0040f270 x; return &x; }
