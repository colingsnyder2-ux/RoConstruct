// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc700 { void reg(void*); };
extern Obj_005cc700 g_obj_005cc700;
extern void* g_arg_005cc700;
extern void cb_005cc700();
extern void tail_005cc700(void*);
extern void* __stdcall make_005cc700(void*, int);
struct X_005cc700 { X_005cc700(); };
X_005cc700::X_005cc700() { void* p=make_005cc700(g_arg_005cc700,27); g_obj_005cc700.reg(p); tail_005cc700((void*)&cb_005cc700); }
X_005cc700* func_005cc700() { static X_005cc700 x; return &x; }
