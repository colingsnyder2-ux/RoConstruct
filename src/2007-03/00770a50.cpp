// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00770a50 { Obj_00770a50* get(); }; extern "C" void reg_00770a50(void*,void*); extern "C" void* make_00770a50(); extern "C" Obj_00770a50* __stdcall wrap_00770a50(void*); extern "C" void final_00770a50(void*);
void func_00770a50() { void* local; reg_00770a50((void*)0x49d090,(void*)0x8b8f14); local=make_00770a50(); Obj_00770a50* o=wrap_00770a50(&local)->get(); *(void**)o=(void*)0x890d74; final_00770a50((void*)0x778b40); }
