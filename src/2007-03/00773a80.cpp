// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00773a80 { Obj_00773a80* get(); }; extern "C" void reg_00773a80(void*,void*); extern "C" void* make_00773a80(); extern "C" Obj_00773a80* __stdcall wrap_00773a80(void*); extern "C" void final_00773a80(void*);
void func_00773a80() { void* local; reg_00773a80((void*)0x5883b0,(void*)0x8bd864); local=make_00773a80(); Obj_00773a80* o=wrap_00773a80(&local)->get(); *(void**)o=(void*)0x8a1cf0; final_00773a80((void*)0x77a690); }
