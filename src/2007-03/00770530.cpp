// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00770530 { Obj_00770530* get(); }; extern "C" void reg_00770530(void*,void*); extern "C" void* make_00770530(); extern "C" Obj_00770530* __stdcall wrap_00770530(void*); extern "C" void final_00770530(void*);
void func_00770530() { void* local; reg_00770530((void*)0x492a60,(void*)0x8b8934); local=make_00770530(); Obj_00770530* o=wrap_00770530(&local)->get(); *(void**)o=(void*)0x88e244; final_00770530((void*)0x778730); }
