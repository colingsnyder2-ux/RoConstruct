// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ce920 { void reg(void*); };
extern Obj_005ce920 g_obj_005ce920;
extern void* g_arg_005ce920;
extern void cb_005ce920();
extern void tail_005ce920(void*);
extern void* __stdcall make_005ce920(void*, int);
struct X_005ce920 { X_005ce920(); };
X_005ce920::X_005ce920() { void* p=make_005ce920(g_arg_005ce920,27); g_obj_005ce920.reg(p); tail_005ce920((void*)&cb_005ce920); }
X_005ce920* func_005ce920() { static X_005ce920 x; return &x; }
