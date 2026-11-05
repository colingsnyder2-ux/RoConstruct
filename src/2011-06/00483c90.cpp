// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_00483c90 { void reg(void*); };
extern Obj_00483c90 g_obj_00483c90;
extern void* g_arg_00483c90;
extern void cb_00483c90();
extern void tail_00483c90(void*);
extern void* __stdcall make_00483c90(void*, int);
struct X_00483c90 { X_00483c90(); };
X_00483c90::X_00483c90() { void* p=make_00483c90(g_arg_00483c90,27); g_obj_00483c90.reg(p); tail_00483c90((void*)&cb_00483c90); }
X_00483c90* func_00483c90() { static X_00483c90 x; return &x; }
