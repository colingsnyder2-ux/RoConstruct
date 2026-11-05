// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ced80 { void reg(void*); };
extern Obj_005ced80 g_obj_005ced80;
extern void* g_arg_005ced80;
extern void cb_005ced80();
extern void tail_005ced80(void*);
extern void* __stdcall make_005ced80(void*, int);
struct X_005ced80 { X_005ced80(); };
X_005ced80::X_005ced80() { void* p=make_005ced80(g_arg_005ced80,27); g_obj_005ced80.reg(p); tail_005ced80((void*)&cb_005ced80); }
X_005ced80* func_005ced80() { static X_005ced80 x; return &x; }
