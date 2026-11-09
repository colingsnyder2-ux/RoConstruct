// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb350 { void reg(void*); };
extern Obj_005cb350 g_obj_005cb350;
extern void* g_arg_005cb350;
extern void cb_005cb350();
extern void tail_005cb350(void*);
extern void* __stdcall make_005cb350(void*, int);
struct X_005cb350 { X_005cb350(); };
X_005cb350::X_005cb350() { void* p=make_005cb350(g_arg_005cb350,27); g_obj_005cb350.reg(p); tail_005cb350((void*)&cb_005cb350); }
X_005cb350* func_005cb350() { static X_005cb350 x; return &x; }
