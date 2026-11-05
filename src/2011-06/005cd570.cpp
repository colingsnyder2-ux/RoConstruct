// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cd570 { void reg(void*); };
extern Obj_005cd570 g_obj_005cd570;
extern void* g_arg_005cd570;
extern void cb_005cd570();
extern void tail_005cd570(void*);
extern void* __stdcall make_005cd570(void*, int);
struct X_005cd570 { X_005cd570(); };
X_005cd570::X_005cd570() { void* p=make_005cd570(g_arg_005cd570,27); g_obj_005cd570.reg(p); tail_005cd570((void*)&cb_005cd570); }
X_005cd570* func_005cd570() { static X_005cd570 x; return &x; }
