// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_007739c0 { Obj_007739c0* get(); }; extern "C" void reg_007739c0(void*,void*); extern "C" void* make_007739c0(); extern "C" Obj_007739c0* __stdcall wrap_007739c0(void*); extern "C" void final_007739c0(void*);
void func_007739c0() { void* local; reg_007739c0((void*)0x588380,(void*)0x8bd858); local=make_007739c0(); Obj_007739c0* o=wrap_007739c0(&local)->get(); *(void**)o=(void*)0x8a1ce4; final_007739c0((void*)0x77a750); }
