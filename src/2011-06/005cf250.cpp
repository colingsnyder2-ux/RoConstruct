// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cf250 { void reg(void*); };
extern Obj_005cf250 g_obj_005cf250;
extern void* g_arg_005cf250;
extern void cb_005cf250();
extern void tail_005cf250(void*);
extern void* __stdcall make_005cf250(void*, int);
struct X_005cf250 { X_005cf250(); };
X_005cf250::X_005cf250() { void* p=make_005cf250(g_arg_005cf250,27); g_obj_005cf250.reg(p); tail_005cf250((void*)&cb_005cf250); }
X_005cf250* func_005cf250() { static X_005cf250 x; return &x; }
