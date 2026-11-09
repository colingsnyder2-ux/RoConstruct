// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00773180 { Obj_00773180* get(); }; extern "C" void reg_00773180(void*,void*); extern "C" void* make_00773180(); extern "C" Obj_00773180* __stdcall wrap_00773180(void*); extern "C" void final_00773180(void*);
void func_00773180() { void* local; reg_00773180((void*)0x58de40,(void*)0x8c37f0); local=make_00773180(); Obj_00773180* o=wrap_00773180(&local)->get(); *(void**)o=(void*)0x8a453c; final_00773180((void*)0x77ab00); }
