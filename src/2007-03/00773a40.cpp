// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00773a40 { Obj_00773a40* get(); }; extern "C" void reg_00773a40(void*,void*); extern "C" void* make_00773a40(); extern "C" Obj_00773a40* __stdcall wrap_00773a40(void*); extern "C" void final_00773a40(void*);
void func_00773a40() { void* local; reg_00773a40((void*)0x5883a0,(void*)0x8bd860); local=make_00773a40(); Obj_00773a40* o=wrap_00773a40(&local)->get(); *(void**)o=(void*)0x8a1cec; final_00773a40((void*)0x77a6d0); }
