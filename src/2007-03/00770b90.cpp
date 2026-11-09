// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00770b90 { Obj_00770b90* get(); }; extern "C" void reg_00770b90(void*,void*); extern "C" void* make_00770b90(); extern "C" Obj_00770b90* __stdcall wrap_00770b90(void*); extern "C" void final_00770b90(void*);
void func_00770b90() { void* local; reg_00770b90((void*)0x49d0e0,(void*)0x8b8f28); local=make_00770b90(); Obj_00770b90* o=wrap_00770b90(&local)->get(); *(void**)o=(void*)0x890d88; final_00770b90((void*)0x778a00); }
