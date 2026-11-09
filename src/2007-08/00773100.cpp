// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00773100 { Obj_00773100* get(); }; extern "C" void reg_00773100(void*,void*); extern "C" void* make_00773100(); extern "C" Obj_00773100* __stdcall wrap_00773100(void*); extern "C" void final_00773100(void*);
void func_00773100() { void* local; reg_00773100((void*)0x58de20,(void*)0x8c37e8); local=make_00773100(); Obj_00773100* o=wrap_00773100(&local)->get(); *(void**)o=(void*)0x8a4534; final_00773100((void*)0x77ab80); }
