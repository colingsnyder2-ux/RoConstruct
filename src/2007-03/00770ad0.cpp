// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00770ad0 { Obj_00770ad0* get(); }; extern "C" void reg_00770ad0(void*,void*); extern "C" void* make_00770ad0(); extern "C" Obj_00770ad0* __stdcall wrap_00770ad0(void*); extern "C" void final_00770ad0(void*);
void func_00770ad0() { void* local; reg_00770ad0((void*)0x49d0b0,(void*)0x8b8f1c); local=make_00770ad0(); Obj_00770ad0* o=wrap_00770ad0(&local)->get(); *(void**)o=(void*)0x890d7c; final_00770ad0((void*)0x778ac0); }
