// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb510 { void reg(void*); };
extern Obj_005cb510 g_obj_005cb510;
extern void* g_arg_005cb510;
extern void cb_005cb510();
extern void tail_005cb510(void*);
extern void* __stdcall make_005cb510(void*, int);
struct X_005cb510 { X_005cb510(); };
X_005cb510::X_005cb510() { void* p=make_005cb510(g_arg_005cb510,27); g_obj_005cb510.reg(p); tail_005cb510((void*)&cb_005cb510); }
X_005cb510* func_005cb510() { static X_005cb510 x; return &x; }
