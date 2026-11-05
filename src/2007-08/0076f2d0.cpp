// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076f2d0 { Obj_0076f2d0* get(); }; extern "C" void reg_0076f2d0(void*,void*); extern "C" void* make_0076f2d0(); extern "C" Obj_0076f2d0* __stdcall wrap_0076f2d0(void*); extern "C" void final_0076f2d0(void*);
void func_0076f2d0() { void* local; reg_0076f2d0((void*)0x498d80,(void*)0x8be2f4); local=make_0076f2d0(); Obj_0076f2d0* o=wrap_0076f2d0(&local)->get(); *(void**)o=(void*)0x88f6c4; final_0076f2d0((void*)0x7786d0); }
