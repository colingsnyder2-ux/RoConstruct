// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb270 { void reg(void*); };
extern Obj_005cb270 g_obj_005cb270;
extern void* g_arg_005cb270;
extern void cb_005cb270();
extern void tail_005cb270(void*);
extern void* __stdcall make_005cb270(void*, int);
struct X_005cb270 { X_005cb270(); };
X_005cb270::X_005cb270() { void* p=make_005cb270(g_arg_005cb270,27); g_obj_005cb270.reg(p); tail_005cb270((void*)&cb_005cb270); }
X_005cb270* func_005cb270() { static X_005cb270 x; return &x; }
