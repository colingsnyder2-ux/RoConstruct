// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_0040ed00 { void reg(void*); };
extern Obj_0040ed00 g_obj_0040ed00;
extern void* g_arg_0040ed00;
extern void cb_0040ed00();
extern void tail_0040ed00(void*);
extern void* __stdcall make_0040ed00(void*, int);
struct X_0040ed00 { X_0040ed00(); };
X_0040ed00::X_0040ed00() { void* p=make_0040ed00(g_arg_0040ed00,27); g_obj_0040ed00.reg(p); tail_0040ed00((void*)&cb_0040ed00); }
X_0040ed00* func_0040ed00() { static X_0040ed00 x; return &x; }
