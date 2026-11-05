// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076f9a0 { Obj_0076f9a0* get(); }; extern "C" void reg_0076f9a0(void*,void*); extern "C" void* make_0076f9a0(); extern "C" Obj_0076f9a0* __stdcall wrap_0076f9a0(void*); extern "C" void final_0076f9a0(void*);
void func_0076f9a0() { void* local; reg_0076f9a0((void*)0x4a7180,(void*)0x8be96c); local=make_0076f9a0(); Obj_0076f9a0* o=wrap_0076f9a0(&local)->get(); *(void**)o=(void*)0x892aac; final_0076f9a0((void*)0x778a60); }
