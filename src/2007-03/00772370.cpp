// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00772370 { Obj_00772370* get(); }; extern "C" void reg_00772370(void*,void*); extern "C" void* make_00772370(); extern "C" Obj_00772370* __stdcall wrap_00772370(void*); extern "C" void final_00772370(void*);
void func_00772370() { void* local; reg_00772370((void*)0x555e70,(void*)0x8bc2a0); local=make_00772370(); Obj_00772370* o=wrap_00772370(&local)->get(); *(void**)o=(void*)0x89dc30; final_00772370((void*)0x779ac0); }
