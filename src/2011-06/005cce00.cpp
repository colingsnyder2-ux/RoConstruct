// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cce00 { void reg(void*); };
extern Obj_005cce00 g_obj_005cce00;
extern void* g_arg_005cce00;
extern void cb_005cce00();
extern void tail_005cce00(void*);
extern void* __stdcall make_005cce00(void*, int);
struct X_005cce00 { X_005cce00(); };
X_005cce00::X_005cce00() { void* p=make_005cce00(g_arg_005cce00,27); g_obj_005cce00.reg(p); tail_005cce00((void*)&cb_005cce00); }
X_005cce00* func_005cce00() { static X_005cce00 x; return &x; }
