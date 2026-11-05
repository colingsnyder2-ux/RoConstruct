// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00770b50 { Obj_00770b50* get(); }; extern "C" void reg_00770b50(void*,void*); extern "C" void* make_00770b50(); extern "C" Obj_00770b50* __stdcall wrap_00770b50(void*); extern "C" void final_00770b50(void*);
void func_00770b50() { void* local; reg_00770b50((void*)0x49d0d0,(void*)0x8b8f24); local=make_00770b50(); Obj_00770b50* o=wrap_00770b50(&local)->get(); *(void**)o=(void*)0x890d84; final_00770b50((void*)0x778a40); }
