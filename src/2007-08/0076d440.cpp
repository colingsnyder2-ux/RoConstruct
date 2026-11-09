// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076d440 { Obj_0076d440* get(); }; extern "C" void reg_0076d440(void*,void*); extern "C" void* make_0076d440(); extern "C" Obj_0076d440* __stdcall wrap_0076d440(void*); extern "C" void final_0076d440(void*);
void func_0076d440() { void* local; reg_0076d440((void*)0x458680,(void*)0x8bbfd4); local=make_0076d440(); Obj_0076d440* o=wrap_0076d440(&local)->get(); *(void**)o=(void*)0x88a478; final_0076d440((void*)0x777e40); }
