// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_007723b0 { Obj_007723b0* get(); }; extern "C" void reg_007723b0(void*,void*); extern "C" void* make_007723b0(); extern "C" Obj_007723b0* __stdcall wrap_007723b0(void*); extern "C" void final_007723b0(void*);
void func_007723b0() { void* local; reg_007723b0((void*)0x555e80,(void*)0x8bc2a4); local=make_007723b0(); Obj_007723b0* o=wrap_007723b0(&local)->get(); *(void**)o=(void*)0x89dc34; final_007723b0((void*)0x779a80); }
