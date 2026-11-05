// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc150 { void reg(void*); };
extern Obj_005cc150 g_obj_005cc150;
extern void* g_arg_005cc150;
extern void cb_005cc150();
extern void tail_005cc150(void*);
extern void* __stdcall make_005cc150(void*, int);
struct X_005cc150 { X_005cc150(); };
X_005cc150::X_005cc150() { void* p=make_005cc150(g_arg_005cc150,27); g_obj_005cc150.reg(p); tail_005cc150((void*)&cb_005cc150); }
X_005cc150* func_005cc150() { static X_005cc150 x; return &x; }
