// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076eda0 { Obj_0076eda0* get(); }; extern "C" void reg_0076eda0(void*,void*); extern "C" void* make_0076eda0(); extern "C" Obj_0076eda0* __stdcall wrap_0076eda0(void*); extern "C" void final_0076eda0(void*);
void func_0076eda0() { void* local; reg_0076eda0((void*)0x487950,(void*)0x8bdca4); local=make_0076eda0(); Obj_0076eda0* o=wrap_0076eda0(&local)->get(); *(void**)o=(void*)0x88e308; final_0076eda0((void*)0x778300); }
