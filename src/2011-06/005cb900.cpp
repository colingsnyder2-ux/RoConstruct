// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb900 { void reg(void*); };
extern Obj_005cb900 g_obj_005cb900;
extern void* g_arg_005cb900;
extern void cb_005cb900();
extern void tail_005cb900(void*);
extern void* __stdcall make_005cb900(void*, int);
struct X_005cb900 { X_005cb900(); };
X_005cb900::X_005cb900() { void* p=make_005cb900(g_arg_005cb900,27); g_obj_005cb900.reg(p); tail_005cb900((void*)&cb_005cb900); }
X_005cb900* func_005cb900() { static X_005cb900 x; return &x; }
