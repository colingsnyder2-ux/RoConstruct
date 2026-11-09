// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cf640 { void reg(void*); };
extern Obj_005cf640 g_obj_005cf640;
extern void* g_arg_005cf640;
extern void cb_005cf640();
extern void tail_005cf640(void*);
extern void* __stdcall make_005cf640(void*, int);
struct X_005cf640 { X_005cf640(); };
X_005cf640::X_005cf640() { void* p=make_005cf640(g_arg_005cf640,27); g_obj_005cf640.reg(p); tail_005cf640((void*)&cb_005cf640); }
X_005cf640* func_005cf640() { static X_005cf640 x; return &x; }
