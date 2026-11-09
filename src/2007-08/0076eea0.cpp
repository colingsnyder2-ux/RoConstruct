// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076eea0 { Obj_0076eea0* get(); }; extern "C" void reg_0076eea0(void*,void*); extern "C" void* make_0076eea0(); extern "C" Obj_0076eea0* __stdcall wrap_0076eea0(void*); extern "C" void final_0076eea0(void*);
void func_0076eea0() { void* local; reg_0076eea0((void*)0x487990,(void*)0x8bdcb4); local=make_0076eea0(); Obj_0076eea0* o=wrap_0076eea0(&local)->get(); *(void**)o=(void*)0x88e318; final_0076eea0((void*)0x778200); }
