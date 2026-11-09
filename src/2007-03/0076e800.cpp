// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076e800 { Obj_0076e800* get(); }; extern "C" void reg_0076e800(void*,void*); extern "C" void* make_0076e800(); extern "C" Obj_0076e800* __stdcall wrap_0076e800(void*); extern "C" void final_0076e800(void*);
void func_0076e800() { void* local; reg_0076e800((void*)0x4616c0,(void*)0x8b66a8); local=make_0076e800(); Obj_0076e800* o=wrap_0076e800(&local)->get(); *(void**)o=(void*)0x8899f0; final_0076e800((void*)0x777f30); }
