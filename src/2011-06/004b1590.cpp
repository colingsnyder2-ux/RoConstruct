// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_004b1590 { void reg(void*); };
extern Obj_004b1590 g_obj_004b1590;
extern void* g_arg_004b1590;
extern void cb_004b1590();
extern void tail_004b1590(void*);
extern void* __stdcall make_004b1590(void*, int);
struct X_004b1590 { X_004b1590(); };
X_004b1590::X_004b1590() { void* p=make_004b1590(g_arg_004b1590,27); g_obj_004b1590.reg(p); tail_004b1590((void*)&cb_004b1590); }
X_004b1590* func_004b1590() { static X_004b1590 x; return &x; }
