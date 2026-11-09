// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_0040fa90 { void reg(void*); };
extern Obj_0040fa90 g_obj_0040fa90;
extern void* g_arg_0040fa90;
extern void cb_0040fa90();
extern void tail_0040fa90(void*);
extern void* __stdcall make_0040fa90(void*, int);
struct X_0040fa90 { X_0040fa90(); };
X_0040fa90::X_0040fa90() { void* p=make_0040fa90(g_arg_0040fa90,27); g_obj_0040fa90.reg(p); tail_0040fa90((void*)&cb_0040fa90); }
X_0040fa90* func_0040fa90() { static X_0040fa90 x; return &x; }
