// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00773040 { Obj_00773040* get(); }; extern "C" void reg_00773040(void*,void*); extern "C" void* make_00773040(); extern "C" Obj_00773040* __stdcall wrap_00773040(void*); extern "C" void final_00773040(void*);
void func_00773040() { void* local; reg_00773040((void*)0x58ddf0,(void*)0x8c37dc); local=make_00773040(); Obj_00773040* o=wrap_00773040(&local)->get(); *(void**)o=(void*)0x8a4528; final_00773040((void*)0x77ac40); }
