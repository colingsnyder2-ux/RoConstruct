// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cda40 { void reg(void*); };
extern Obj_005cda40 g_obj_005cda40;
extern void* g_arg_005cda40;
extern void cb_005cda40();
extern void tail_005cda40(void*);
extern void* __stdcall make_005cda40(void*, int);
struct X_005cda40 { X_005cda40(); };
X_005cda40::X_005cda40() { void* p=make_005cda40(g_arg_005cda40,27); g_obj_005cda40.reg(p); tail_005cda40((void*)&cb_005cda40); }
X_005cda40* func_005cda40() { static X_005cda40 x; return &x; }
