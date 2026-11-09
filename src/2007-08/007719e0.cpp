// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_007719e0 { Obj_007719e0* get(); }; extern "C" void reg_007719e0(void*,void*); extern "C" void* make_007719e0(); extern "C" Obj_007719e0* __stdcall wrap_007719e0(void*); extern "C" void final_007719e0(void*);
void func_007719e0() { void* local; reg_007719e0((void*)0x55ed40,(void*)0x8c231c); local=make_007719e0(); Obj_007719e0* o=wrap_007719e0(&local)->get(); *(void**)o=(void*)0x89f378; final_007719e0((void*)0x779d80); }
