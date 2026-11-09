// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076d830 { Obj_0076d830* get(); }; extern "C" void reg_0076d830(void*,void*); extern "C" void* make_0076d830(); extern "C" Obj_0076d830* __stdcall wrap_0076d830(void*); extern "C" void final_0076d830(void*);
void func_0076d830() { void* local; reg_0076d830((void*)0x4034b0,(void*)0x8b53d4); local=make_0076d830(); Obj_0076d830* o=wrap_0076d830(&local)->get(); *(void**)o=(void*)0x880360; final_0076d830((void*)0x777310); }
