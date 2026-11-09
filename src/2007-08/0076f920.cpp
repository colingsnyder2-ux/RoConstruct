// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076f920 { Obj_0076f920* get(); }; extern "C" void reg_0076f920(void*,void*); extern "C" void* make_0076f920(); extern "C" Obj_0076f920* __stdcall wrap_0076f920(void*); extern "C" void final_0076f920(void*);
void func_0076f920() { void* local; reg_0076f920((void*)0x4a7160,(void*)0x8be964); local=make_0076f920(); Obj_0076f920* o=wrap_0076f920(&local)->get(); *(void**)o=(void*)0x892aa4; final_0076f920((void*)0x778ae0); }
