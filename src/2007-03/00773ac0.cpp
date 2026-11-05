// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00773ac0 { Obj_00773ac0* get(); }; extern "C" void reg_00773ac0(void*,void*); extern "C" void* make_00773ac0(); extern "C" Obj_00773ac0* __stdcall wrap_00773ac0(void*); extern "C" void final_00773ac0(void*);
void func_00773ac0() { void* local; reg_00773ac0((void*)0x5883c0,(void*)0x8bd868); local=make_00773ac0(); Obj_00773ac0* o=wrap_00773ac0(&local)->get(); *(void**)o=(void*)0x8a1cf4; final_00773ac0((void*)0x77a650); }
