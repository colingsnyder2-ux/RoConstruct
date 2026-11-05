// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076c7a0 { Obj_0076c7a0* get(); }; extern "C" void reg_0076c7a0(void*,void*); extern "C" void* make_0076c7a0(); extern "C" Obj_0076c7a0* __stdcall wrap_0076c7a0(void*); extern "C" void final_0076c7a0(void*);
void func_0076c7a0() { void* local; reg_0076c7a0((void*)0x40d280,(void*)0x8baf84); local=make_0076c7a0(); Obj_0076c7a0* o=wrap_0076c7a0(&local)->get(); *(void**)o=(void*)0x8824c4; final_0076c7a0((void*)0x777360); }
