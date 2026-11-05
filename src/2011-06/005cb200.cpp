// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb200 { void reg(void*); };
extern Obj_005cb200 g_obj_005cb200;
extern void* g_arg_005cb200;
extern void cb_005cb200();
extern void tail_005cb200(void*);
extern void* __stdcall make_005cb200(void*, int);
struct X_005cb200 { X_005cb200(); };
X_005cb200::X_005cb200() { void* p=make_005cb200(g_arg_005cb200,27); g_obj_005cb200.reg(p); tail_005cb200((void*)&cb_005cb200); }
X_005cb200* func_005cb200() { static X_005cb200 x; return &x; }
