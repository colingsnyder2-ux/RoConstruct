// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ce060 { void reg(void*); };
extern Obj_005ce060 g_obj_005ce060;
extern void* g_arg_005ce060;
extern void cb_005ce060();
extern void tail_005ce060(void*);
extern void* __stdcall make_005ce060(void*, int);
struct X_005ce060 { X_005ce060(); };
X_005ce060::X_005ce060() { void* p=make_005ce060(g_arg_005ce060,27); g_obj_005ce060.reg(p); tail_005ce060((void*)&cb_005ce060); }
X_005ce060* func_005ce060() { static X_005ce060 x; return &x; }
