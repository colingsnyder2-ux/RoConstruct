// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cab70 { void reg(void*); };
extern Obj_005cab70 g_obj_005cab70;
extern void* g_arg_005cab70;
extern void cb_005cab70();
extern void tail_005cab70(void*);
extern void* __stdcall make_005cab70(void*, int);
struct X_005cab70 { X_005cab70(); };
X_005cab70::X_005cab70() { void* p=make_005cab70(g_arg_005cab70,27); g_obj_005cab70.reg(p); tail_005cab70((void*)&cb_005cab70); }
X_005cab70* func_005cab70() { static X_005cab70 x; return &x; }
