// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cd500 { void reg(void*); };
extern Obj_005cd500 g_obj_005cd500;
extern void* g_arg_005cd500;
extern void cb_005cd500();
extern void tail_005cd500(void*);
extern void* __stdcall make_005cd500(void*, int);
struct X_005cd500 { X_005cd500(); };
X_005cd500::X_005cd500() { void* p=make_005cd500(g_arg_005cd500,27); g_obj_005cd500.reg(p); tail_005cd500((void*)&cb_005cd500); }
X_005cd500* func_005cd500() { static X_005cd500 x; return &x; }
