// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005caa90 { void reg(void*); };
extern Obj_005caa90 g_obj_005caa90;
extern void* g_arg_005caa90;
extern void cb_005caa90();
extern void tail_005caa90(void*);
extern void* __stdcall make_005caa90(void*, int);
struct X_005caa90 { X_005caa90(); };
X_005caa90::X_005caa90() { void* p=make_005caa90(g_arg_005caa90,27); g_obj_005caa90.reg(p); tail_005caa90((void*)&cb_005caa90); }
X_005caa90* func_005caa90() { static X_005caa90 x; return &x; }
