// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076d990 { Obj_0076d990* get(); }; extern "C" void reg_0076d990(void*,void*); extern "C" void* make_0076d990(); extern "C" Obj_0076d990* __stdcall wrap_0076d990(void*); extern "C" void final_0076d990(void*);
void func_0076d990() { void* local; reg_0076d990((void*)0x408ea0,(void*)0x8b5450); local=make_0076d990(); Obj_0076d990* o=wrap_0076d990(&local)->get(); *(void**)o=(void*)0x880978; final_0076d990((void*)0x7773b0); }
