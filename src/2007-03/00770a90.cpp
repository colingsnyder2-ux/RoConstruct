// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00770a90 { Obj_00770a90* get(); }; extern "C" void reg_00770a90(void*,void*); extern "C" void* make_00770a90(); extern "C" Obj_00770a90* __stdcall wrap_00770a90(void*); extern "C" void final_00770a90(void*);
void func_00770a90() { void* local; reg_00770a90((void*)0x49d0a0,(void*)0x8b8f18); local=make_00770a90(); Obj_00770a90* o=wrap_00770a90(&local)->get(); *(void**)o=(void*)0x890d78; final_00770a90((void*)0x778b00); }
