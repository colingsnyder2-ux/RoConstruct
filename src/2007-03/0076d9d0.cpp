// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076d9d0 { Obj_0076d9d0* get(); }; extern "C" void reg_0076d9d0(void*,void*); extern "C" void* make_0076d9d0(); extern "C" Obj_0076d9d0* __stdcall wrap_0076d9d0(void*); extern "C" void final_0076d9d0(void*);
void func_0076d9d0() { void* local; reg_0076d9d0((void*)0x40e2f0,(void*)0x8b54b0); local=make_0076d9d0(); Obj_0076d9d0* o=wrap_0076d9d0(&local)->get(); *(void**)o=(void*)0x8815f8; final_0076d9d0((void*)0x777430); }
