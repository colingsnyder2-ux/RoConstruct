// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076eca0 { Obj_0076eca0* get(); }; extern "C" void reg_0076eca0(void*,void*); extern "C" void* make_0076eca0(); extern "C" Obj_0076eca0* __stdcall wrap_0076eca0(void*); extern "C" void final_0076eca0(void*);
void func_0076eca0() { void* local; reg_0076eca0((void*)0x487910,(void*)0x8bdc94); local=make_0076eca0(); Obj_0076eca0* o=wrap_0076eca0(&local)->get(); *(void**)o=(void*)0x88e2f8; final_0076eca0((void*)0x778400); }
