// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076d870 { Obj_0076d870* get(); }; extern "C" void reg_0076d870(void*,void*); extern "C" void* make_0076d870(); extern "C" Obj_0076d870* __stdcall wrap_0076d870(void*); extern "C" void final_0076d870(void*);
void func_0076d870() { void* local; reg_0076d870((void*)0x4034c0,(void*)0x8b53d8); local=make_0076d870(); Obj_0076d870* o=wrap_0076d870(&local)->get(); *(void**)o=(void*)0x880364; final_0076d870((void*)0x7772d0); }
