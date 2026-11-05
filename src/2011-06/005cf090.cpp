// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cf090 { void reg(void*); };
extern Obj_005cf090 g_obj_005cf090;
extern void* g_arg_005cf090;
extern void cb_005cf090();
extern void tail_005cf090(void*);
extern void* __stdcall make_005cf090(void*, int);
struct X_005cf090 { X_005cf090(); };
X_005cf090::X_005cf090() { void* p=make_005cf090(g_arg_005cf090,3); g_obj_005cf090.reg(p); tail_005cf090((void*)&cb_005cf090); }
X_005cf090* func_005cf090() { static X_005cf090 x; return &x; }
