// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076e5a0 { Obj_0076e5a0* get(); }; extern "C" void reg_0076e5a0(void*,void*); extern "C" void* make_0076e5a0(); extern "C" Obj_0076e5a0* __stdcall wrap_0076e5a0(void*); extern "C" void final_0076e5a0(void*);
void func_0076e5a0() { void* local; reg_0076e5a0((void*)0x4481b0,(void*)0x8b63d4); local=make_0076e5a0(); Obj_0076e5a0* o=wrap_0076e5a0(&local)->get(); *(void**)o=(void*)0x888024; final_0076e5a0((void*)0x777db0); }
