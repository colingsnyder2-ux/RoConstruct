// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076c6e0 { Obj_0076c6e0* get(); }; extern "C" void reg_0076c6e0(void*,void*); extern "C" void* make_0076c6e0(); extern "C" Obj_0076c6e0* __stdcall wrap_0076c6e0(void*); extern "C" void final_0076c6e0(void*);
void func_0076c6e0() { void* local; reg_0076c6e0((void*)0x4035d0,(void*)0x8baecc); local=make_0076c6e0(); Obj_0076c6e0* o=wrap_0076c6e0(&local)->get(); *(void**)o=(void*)0x881370; final_0076c6e0((void*)0x777190); }
