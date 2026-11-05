// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb580 { void reg(void*); };
extern Obj_005cb580 g_obj_005cb580;
extern void* g_arg_005cb580;
extern void cb_005cb580();
extern void tail_005cb580(void*);
extern void* __stdcall make_005cb580(void*, int);
struct X_005cb580 { X_005cb580(); };
X_005cb580::X_005cb580() { void* p=make_005cb580(g_arg_005cb580,27); g_obj_005cb580.reg(p); tail_005cb580((void*)&cb_005cb580); }
X_005cb580* func_005cb580() { static X_005cb580 x; return &x; }
