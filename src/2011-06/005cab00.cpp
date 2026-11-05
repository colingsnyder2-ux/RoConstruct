// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cab00 { void reg(void*); };
extern Obj_005cab00 g_obj_005cab00;
extern void* g_arg_005cab00;
extern void cb_005cab00();
extern void tail_005cab00(void*);
extern void* __stdcall make_005cab00(void*, int);
struct X_005cab00 { X_005cab00(); };
X_005cab00::X_005cab00() { void* p=make_005cab00(g_arg_005cab00,27); g_obj_005cab00.reg(p); tail_005cab00((void*)&cb_005cab00); }
X_005cab00* func_005cab00() { static X_005cab00 x; return &x; }
