// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cd650 { void reg(void*); };
extern Obj_005cd650 g_obj_005cd650;
extern void* g_arg_005cd650;
extern void cb_005cd650();
extern void tail_005cd650(void*);
extern void* __stdcall make_005cd650(void*, int);
struct X_005cd650 { X_005cd650(); };
X_005cd650::X_005cd650() { void* p=make_005cd650(g_arg_005cd650,5); g_obj_005cd650.reg(p); tail_005cd650((void*)&cb_005cd650); }
X_005cd650* func_005cd650() { static X_005cd650 x; return &x; }
