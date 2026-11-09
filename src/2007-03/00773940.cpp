// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00773940 { Obj_00773940* get(); }; extern "C" void reg_00773940(void*,void*); extern "C" void* make_00773940(); extern "C" Obj_00773940* __stdcall wrap_00773940(void*); extern "C" void final_00773940(void*);
void func_00773940() { void* local; reg_00773940((void*)0x588360,(void*)0x8bd850); local=make_00773940(); Obj_00773940* o=wrap_00773940(&local)->get(); *(void**)o=(void*)0x8a1cdc; final_00773940((void*)0x77a7d0); }
