// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ca710 { void reg(void*); };
extern Obj_005ca710 g_obj_005ca710;
extern void* g_arg_005ca710;
extern void cb_005ca710();
extern void tail_005ca710(void*);
extern void* __stdcall make_005ca710(void*, int);
struct X_005ca710 { X_005ca710(); };
X_005ca710::X_005ca710() { void* p=make_005ca710(g_arg_005ca710,27); g_obj_005ca710.reg(p); tail_005ca710((void*)&cb_005ca710); }
X_005ca710* func_005ca710() { static X_005ca710 x; return &x; }
