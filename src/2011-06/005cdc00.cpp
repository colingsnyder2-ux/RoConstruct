// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cdc00 { void reg(void*); };
extern Obj_005cdc00 g_obj_005cdc00;
extern void* g_arg_005cdc00;
extern void cb_005cdc00();
extern void tail_005cdc00(void*);
extern void* __stdcall make_005cdc00(void*, int);
struct X_005cdc00 { X_005cdc00(); };
X_005cdc00::X_005cdc00() { void* p=make_005cdc00(g_arg_005cdc00,27); g_obj_005cdc00.reg(p); tail_005cdc00((void*)&cb_005cdc00); }
X_005cdc00* func_005cdc00() { static X_005cdc00 x; return &x; }
