// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb890 { void reg(void*); };
extern Obj_005cb890 g_obj_005cb890;
extern void* g_arg_005cb890;
extern void cb_005cb890();
extern void tail_005cb890(void*);
extern void* __stdcall make_005cb890(void*, int);
struct X_005cb890 { X_005cb890(); };
X_005cb890::X_005cb890() { void* p=make_005cb890(g_arg_005cb890,27); g_obj_005cb890.reg(p); tail_005cb890((void*)&cb_005cb890); }
X_005cb890* func_005cb890() { static X_005cb890 x; return &x; }
