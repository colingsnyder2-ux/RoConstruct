// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076c5e0 { Obj_0076c5e0* get(); }; extern "C" void reg_0076c5e0(void*,void*); extern "C" void* make_0076c5e0(); extern "C" Obj_0076c5e0* __stdcall wrap_0076c5e0(void*); extern "C" void final_0076c5e0(void*);
void func_0076c5e0() { void* local; reg_0076c5e0((void*)0x403590,(void*)0x8baebc); local=make_0076c5e0(); Obj_0076c5e0* o=wrap_0076c5e0(&local)->get(); *(void**)o=(void*)0x881360; final_0076c5e0((void*)0x777290); }
