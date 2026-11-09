// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cd260 { void reg(void*); };
extern Obj_005cd260 g_obj_005cd260;
extern void* g_arg_005cd260;
extern void cb_005cd260();
extern void tail_005cd260(void*);
extern void* __stdcall make_005cd260(void*, int);
struct X_005cd260 { X_005cd260(); };
X_005cd260::X_005cd260() { void* p=make_005cd260(g_arg_005cd260,27); g_obj_005cd260.reg(p); tail_005cd260((void*)&cb_005cd260); }
X_005cd260* func_005cd260() { static X_005cd260 x; return &x; }
