// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cdc70 { void reg(void*); };
extern Obj_005cdc70 g_obj_005cdc70;
extern void* g_arg_005cdc70;
extern void cb_005cdc70();
extern void tail_005cdc70(void*);
extern void* __stdcall make_005cdc70(void*, int);
struct X_005cdc70 { X_005cdc70(); };
X_005cdc70::X_005cdc70() { void* p=make_005cdc70(g_arg_005cdc70,27); g_obj_005cdc70.reg(p); tail_005cdc70((void*)&cb_005cdc70); }
X_005cdc70* func_005cdc70() { static X_005cdc70 x; return &x; }
