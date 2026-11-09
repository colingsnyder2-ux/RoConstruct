// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc930 { void reg(void*); };
extern Obj_005cc930 g_obj_005cc930;
extern void* g_arg_005cc930;
extern void cb_005cc930();
extern void tail_005cc930(void*);
extern void* __stdcall make_005cc930(void*, int);
struct X_005cc930 { X_005cc930(); };
X_005cc930::X_005cc930() { void* p=make_005cc930(g_arg_005cc930,27); g_obj_005cc930.reg(p); tail_005cc930((void*)&cb_005cc930); }
X_005cc930* func_005cc930() { static X_005cc930 x; return &x; }
