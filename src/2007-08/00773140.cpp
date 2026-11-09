// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00773140 { Obj_00773140* get(); }; extern "C" void reg_00773140(void*,void*); extern "C" void* make_00773140(); extern "C" Obj_00773140* __stdcall wrap_00773140(void*); extern "C" void final_00773140(void*);
void func_00773140() { void* local; reg_00773140((void*)0x58de30,(void*)0x8c37ec); local=make_00773140(); Obj_00773140* o=wrap_00773140(&local)->get(); *(void**)o=(void*)0x8a4538; final_00773140((void*)0x77ab40); }
