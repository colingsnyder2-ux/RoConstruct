// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076d3a0 { Obj_0076d3a0* get(); }; extern "C" void reg_0076d3a0(void*,void*); extern "C" void* make_0076d3a0(); extern "C" Obj_0076d3a0* __stdcall wrap_0076d3a0(void*); extern "C" void final_0076d3a0(void*);
void func_0076d3a0() { void* local; reg_0076d3a0((void*)0x44de00,(void*)0x8bbee4); local=make_0076d3a0(); Obj_0076d3a0* o=wrap_0076d3a0(&local)->get(); *(void**)o=(void*)0x8896a8; final_0076d3a0((void*)0x777dd0); }
