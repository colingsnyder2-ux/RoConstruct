// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cea70 { void reg(void*); };
extern Obj_005cea70 g_obj_005cea70;
extern void* g_arg_005cea70;
extern void cb_005cea70();
extern void tail_005cea70(void*);
extern void* __stdcall make_005cea70(void*, int);
struct X_005cea70 { X_005cea70(); };
X_005cea70::X_005cea70() { void* p=make_005cea70(g_arg_005cea70,27); g_obj_005cea70.reg(p); tail_005cea70((void*)&cb_005cea70); }
X_005cea70* func_005cea70() { static X_005cea70 x; return &x; }
