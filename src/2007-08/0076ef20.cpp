// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ef20 { Obj_0076ef20* get(); }; extern "C" void reg_0076ef20(void*,void*); extern "C" void* make_0076ef20(); extern "C" Obj_0076ef20* __stdcall wrap_0076ef20(void*); extern "C" void final_0076ef20(void*);
void func_0076ef20() { void* local; reg_0076ef20((void*)0x4879b0,(void*)0x8bdcbc); local=make_0076ef20(); Obj_0076ef20* o=wrap_0076ef20(&local)->get(); *(void**)o=(void*)0x88e320; final_0076ef20((void*)0x778180); }
