// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ccd90 { void reg(void*); };
extern Obj_005ccd90 g_obj_005ccd90;
extern void* g_arg_005ccd90;
extern void cb_005ccd90();
extern void tail_005ccd90(void*);
extern void* __stdcall make_005ccd90(void*, int);
struct X_005ccd90 { X_005ccd90(); };
X_005ccd90::X_005ccd90() { void* p=make_005ccd90(g_arg_005ccd90,27); g_obj_005ccd90.reg(p); tail_005ccd90((void*)&cb_005ccd90); }
X_005ccd90* func_005ccd90() { static X_005ccd90 x; return &x; }
