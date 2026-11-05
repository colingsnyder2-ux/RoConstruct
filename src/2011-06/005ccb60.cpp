// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ccb60 { void reg(void*); };
extern Obj_005ccb60 g_obj_005ccb60;
extern void* g_arg_005ccb60;
extern void cb_005ccb60();
extern void tail_005ccb60(void*);
extern void* __stdcall make_005ccb60(void*, int);
struct X_005ccb60 { X_005ccb60(); };
X_005ccb60::X_005ccb60() { void* p=make_005ccb60(g_arg_005ccb60,27); g_obj_005ccb60.reg(p); tail_005ccb60((void*)&cb_005ccb60); }
X_005ccb60* func_005ccb60() { static X_005ccb60 x; return &x; }
