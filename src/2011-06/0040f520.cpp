// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_0040f520 { void reg(void*); };
extern Obj_0040f520 g_obj_0040f520;
extern void* g_arg_0040f520;
extern void cb_0040f520();
extern void tail_0040f520(void*);
extern void* __stdcall make_0040f520(void*, int);
struct X_0040f520 { X_0040f520(); };
X_0040f520::X_0040f520() { void* p=make_0040f520(g_arg_0040f520,27); g_obj_0040f520.reg(p); tail_0040f520((void*)&cb_0040f520); }
X_0040f520* func_0040f520() { static X_0040f520 x; return &x; }
