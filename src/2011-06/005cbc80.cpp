// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cbc80 { void reg(void*); };
extern Obj_005cbc80 g_obj_005cbc80;
extern void* g_arg_005cbc80;
extern void cb_005cbc80();
extern void tail_005cbc80(void*);
extern void* __stdcall make_005cbc80(void*, int);
struct X_005cbc80 { X_005cbc80(); };
X_005cbc80::X_005cbc80() { void* p=make_005cbc80(g_arg_005cbc80,27); g_obj_005cbc80.reg(p); tail_005cbc80((void*)&cb_005cbc80); }
X_005cbc80* func_005cbc80() { static X_005cbc80 x; return &x; }
