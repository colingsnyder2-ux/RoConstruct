// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ca780 { void reg(void*); };
extern Obj_005ca780 g_obj_005ca780;
extern void* g_arg_005ca780;
extern void cb_005ca780();
extern void tail_005ca780(void*);
extern void* __stdcall make_005ca780(void*, int);
struct X_005ca780 { X_005ca780(); };
X_005ca780::X_005ca780() { void* p=make_005ca780(g_arg_005ca780,27); g_obj_005ca780.reg(p); tail_005ca780((void*)&cb_005ca780); }
X_005ca780* func_005ca780() { static X_005ca780 x; return &x; }
