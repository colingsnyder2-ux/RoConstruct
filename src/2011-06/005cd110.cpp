// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cd110 { void reg(void*); };
extern Obj_005cd110 g_obj_005cd110;
extern void* g_arg_005cd110;
extern void cb_005cd110();
extern void tail_005cd110(void*);
extern void* __stdcall make_005cd110(void*, int);
struct X_005cd110 { X_005cd110(); };
X_005cd110::X_005cd110() { void* p=make_005cd110(g_arg_005cd110,27); g_obj_005cd110.reg(p); tail_005cd110((void*)&cb_005cd110); }
X_005cd110* func_005cd110() { static X_005cd110 x; return &x; }
