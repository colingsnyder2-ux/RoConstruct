// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076e6a0 { Obj_0076e6a0* get(); }; extern "C" void reg_0076e6a0(void*,void*); extern "C" void* make_0076e6a0(); extern "C" Obj_0076e6a0* __stdcall wrap_0076e6a0(void*); extern "C" void final_0076e6a0(void*);
void func_0076e6a0() { void* local; reg_0076e6a0((void*)0x456060,(void*)0x8b658c); local=make_0076e6a0(); Obj_0076e6a0* o=wrap_0076e6a0(&local)->get(); *(void**)o=(void*)0x889060; final_0076e6a0((void*)0x777e70); }
