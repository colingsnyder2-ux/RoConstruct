// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc460 { void reg(void*); };
extern Obj_005cc460 g_obj_005cc460;
extern void* g_arg_005cc460;
extern void cb_005cc460();
extern void tail_005cc460(void*);
extern void* __stdcall make_005cc460(void*, int);
struct X_005cc460 { X_005cc460(); };
X_005cc460::X_005cc460() { void* p=make_005cc460(g_arg_005cc460,27); g_obj_005cc460.reg(p); tail_005cc460((void*)&cb_005cc460); }
X_005cc460* func_005cc460() { static X_005cc460 x; return &x; }
