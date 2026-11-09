// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cdb90 { void reg(void*); };
extern Obj_005cdb90 g_obj_005cdb90;
extern void* g_arg_005cdb90;
extern void cb_005cdb90();
extern void tail_005cdb90(void*);
extern void* __stdcall make_005cdb90(void*, int);
struct X_005cdb90 { X_005cdb90(); };
X_005cdb90::X_005cdb90() { void* p=make_005cdb90(g_arg_005cdb90,27); g_obj_005cdb90.reg(p); tail_005cdb90((void*)&cb_005cdb90); }
X_005cdb90* func_005cdb90() { static X_005cdb90 x; return &x; }
