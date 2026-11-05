// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cf170 { void reg(void*); };
extern Obj_005cf170 g_obj_005cf170;
extern void* g_arg_005cf170;
extern void cb_005cf170();
extern void tail_005cf170(void*);
extern void* __stdcall make_005cf170(void*, int);
struct X_005cf170 { X_005cf170(); };
X_005cf170::X_005cf170() { void* p=make_005cf170(g_arg_005cf170,27); g_obj_005cf170.reg(p); tail_005cf170((void*)&cb_005cf170); }
X_005cf170* func_005cf170() { static X_005cf170 x; return &x; }
