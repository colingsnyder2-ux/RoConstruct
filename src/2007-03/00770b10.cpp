// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00770b10 { Obj_00770b10* get(); }; extern "C" void reg_00770b10(void*,void*); extern "C" void* make_00770b10(); extern "C" Obj_00770b10* __stdcall wrap_00770b10(void*); extern "C" void final_00770b10(void*);
void func_00770b10() { void* local; reg_00770b10((void*)0x49d0c0,(void*)0x8b8f20); local=make_00770b10(); Obj_00770b10* o=wrap_00770b10(&local)->get(); *(void**)o=(void*)0x890d80; final_00770b10((void*)0x778a80); }
