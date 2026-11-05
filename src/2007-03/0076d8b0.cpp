// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076d8b0 { Obj_0076d8b0* get(); }; extern "C" void reg_0076d8b0(void*,void*); extern "C" void* make_0076d8b0(); extern "C" Obj_0076d8b0* __stdcall wrap_0076d8b0(void*); extern "C" void final_0076d8b0(void*);
void func_0076d8b0() { void* local; reg_0076d8b0((void*)0x4034d0,(void*)0x8b53dc); local=make_0076d8b0(); Obj_0076d8b0* o=wrap_0076d8b0(&local)->get(); *(void**)o=(void*)0x880368; final_0076d8b0((void*)0x777290); }
