// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb430 { void reg(void*); };
extern Obj_005cb430 g_obj_005cb430;
extern void* g_arg_005cb430;
extern void cb_005cb430();
extern void tail_005cb430(void*);
extern void* __stdcall make_005cb430(void*, int);
struct X_005cb430 { X_005cb430(); };
X_005cb430::X_005cb430() { void* p=make_005cb430(g_arg_005cb430,27); g_obj_005cb430.reg(p); tail_005cb430((void*)&cb_005cb430); }
X_005cb430* func_005cb430() { static X_005cb430 x; return &x; }
