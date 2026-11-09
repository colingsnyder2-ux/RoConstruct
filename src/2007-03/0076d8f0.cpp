// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076d8f0 { Obj_0076d8f0* get(); }; extern "C" void reg_0076d8f0(void*,void*); extern "C" void* make_0076d8f0(); extern "C" Obj_0076d8f0* __stdcall wrap_0076d8f0(void*); extern "C" void final_0076d8f0(void*);
void func_0076d8f0() { void* local; reg_0076d8f0((void*)0x4034e0,(void*)0x8b53e0); local=make_0076d8f0(); Obj_0076d8f0* o=wrap_0076d8f0(&local)->get(); *(void**)o=(void*)0x88036c; final_0076d8f0((void*)0x777250); }
