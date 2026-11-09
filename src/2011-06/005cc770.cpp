// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc770 { void reg(void*); };
extern Obj_005cc770 g_obj_005cc770;
extern void* g_arg_005cc770;
extern void cb_005cc770();
extern void tail_005cc770(void*);
extern void* __stdcall make_005cc770(void*, int);
struct X_005cc770 { X_005cc770(); };
X_005cc770::X_005cc770() { void* p=make_005cc770(g_arg_005cc770,27); g_obj_005cc770.reg(p); tail_005cc770((void*)&cb_005cc770); }
X_005cc770* func_005cc770() { static X_005cc770 x; return &x; }
