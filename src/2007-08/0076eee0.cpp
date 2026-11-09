// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076eee0 { Obj_0076eee0* get(); }; extern "C" void reg_0076eee0(void*,void*); extern "C" void* make_0076eee0(); extern "C" Obj_0076eee0* __stdcall wrap_0076eee0(void*); extern "C" void final_0076eee0(void*);
void func_0076eee0() { void* local; reg_0076eee0((void*)0x4879a0,(void*)0x8bdcb8); local=make_0076eee0(); Obj_0076eee0* o=wrap_0076eee0(&local)->get(); *(void**)o=(void*)0x88e31c; final_0076eee0((void*)0x7781c0); }
