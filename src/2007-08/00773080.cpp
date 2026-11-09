// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00773080 { Obj_00773080* get(); }; extern "C" void reg_00773080(void*,void*); extern "C" void* make_00773080(); extern "C" Obj_00773080* __stdcall wrap_00773080(void*); extern "C" void final_00773080(void*);
void func_00773080() { void* local; reg_00773080((void*)0x58de00,(void*)0x8c37e0); local=make_00773080(); Obj_00773080* o=wrap_00773080(&local)->get(); *(void**)o=(void*)0x8a452c; final_00773080((void*)0x77ac00); }
