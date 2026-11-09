// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_007714c0 { Obj_007714c0* get(); }; extern "C" void reg_007714c0(void*,void*); extern "C" void* make_007714c0(); extern "C" Obj_007714c0* __stdcall wrap_007714c0(void*); extern "C" void final_007714c0(void*);
void func_007714c0() { void* local; reg_007714c0((void*)0x558700,(void*)0x8c1f14); local=make_007714c0(); Obj_007714c0* o=wrap_007714c0(&local)->get(); *(void**)o=(void*)0x89ebcc; final_007714c0((void*)0x779bc0); }
