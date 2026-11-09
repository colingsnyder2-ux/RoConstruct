// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00773980 { Obj_00773980* get(); }; extern "C" void reg_00773980(void*,void*); extern "C" void* make_00773980(); extern "C" Obj_00773980* __stdcall wrap_00773980(void*); extern "C" void final_00773980(void*);
void func_00773980() { void* local; reg_00773980((void*)0x588370,(void*)0x8bd854); local=make_00773980(); Obj_00773980* o=wrap_00773980(&local)->get(); *(void**)o=(void*)0x8a1ce0; final_00773980((void*)0x77a790); }
