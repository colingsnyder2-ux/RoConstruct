// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cd960 { void reg(void*); };
extern Obj_005cd960 g_obj_005cd960;
extern void* g_arg_005cd960;
extern void cb_005cd960();
extern void tail_005cd960(void*);
extern void* __stdcall make_005cd960(void*, int);
struct X_005cd960 { X_005cd960(); };
X_005cd960::X_005cd960() { void* p=make_005cd960(g_arg_005cd960,27); g_obj_005cd960.reg(p); tail_005cd960((void*)&cb_005cd960); }
X_005cd960* func_005cd960() { static X_005cd960 x; return &x; }
