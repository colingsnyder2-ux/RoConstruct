// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ca940 { void reg(void*); };
extern Obj_005ca940 g_obj_005ca940;
extern void* g_arg_005ca940;
extern void cb_005ca940();
extern void tail_005ca940(void*);
extern void* __stdcall make_005ca940(void*, int);
struct X_005ca940 { X_005ca940(); };
X_005ca940::X_005ca940() { void* p=make_005ca940(g_arg_005ca940,27); g_obj_005ca940.reg(p); tail_005ca940((void*)&cb_005ca940); }
X_005ca940* func_005ca940() { static X_005ca940 x; return &x; }
