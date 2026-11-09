// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00773000 { Obj_00773000* get(); }; extern "C" void reg_00773000(void*,void*); extern "C" void* make_00773000(); extern "C" Obj_00773000* __stdcall wrap_00773000(void*); extern "C" void final_00773000(void*);
void func_00773000() { void* local; reg_00773000((void*)0x58dde0,(void*)0x8c37d8); local=make_00773000(); Obj_00773000* o=wrap_00773000(&local)->get(); *(void**)o=(void*)0x8a4524; final_00773000((void*)0x77ac80); }
