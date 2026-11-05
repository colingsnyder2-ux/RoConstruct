// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb820 { void reg(void*); };
extern Obj_005cb820 g_obj_005cb820;
extern void* g_arg_005cb820;
extern void cb_005cb820();
extern void tail_005cb820(void*);
extern void* __stdcall make_005cb820(void*, int);
struct X_005cb820 { X_005cb820(); };
X_005cb820::X_005cb820() { void* p=make_005cb820(g_arg_005cb820,27); g_obj_005cb820.reg(p); tail_005cb820((void*)&cb_005cb820); }
X_005cb820* func_005cb820() { static X_005cb820 x; return &x; }
