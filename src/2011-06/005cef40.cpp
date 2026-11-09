// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cef40 { void reg(void*); };
extern Obj_005cef40 g_obj_005cef40;
extern void* g_arg_005cef40;
extern void cb_005cef40();
extern void tail_005cef40(void*);
extern void* __stdcall make_005cef40(void*, int);
struct X_005cef40 { X_005cef40(); };
X_005cef40::X_005cef40() { void* p=make_005cef40(g_arg_005cef40,27); g_obj_005cef40.reg(p); tail_005cef40((void*)&cb_005cef40); }
X_005cef40* func_005cef40() { static X_005cef40 x; return &x; }
