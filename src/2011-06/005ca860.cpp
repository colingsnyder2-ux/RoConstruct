// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ca860 { void reg(void*); };
extern Obj_005ca860 g_obj_005ca860;
extern void* g_arg_005ca860;
extern void cb_005ca860();
extern void tail_005ca860(void*);
extern void* __stdcall make_005ca860(void*, int);
struct X_005ca860 { X_005ca860(); };
X_005ca860::X_005ca860() { void* p=make_005ca860(g_arg_005ca860,27); g_obj_005ca860.reg(p); tail_005ca860((void*)&cb_005ca860); }
X_005ca860* func_005ca860() { static X_005ca860 x; return &x; }
