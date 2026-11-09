// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00772e40 { Obj_00772e40* get(); }; extern "C" void reg_00772e40(void*,void*); extern "C" void* make_00772e40(); extern "C" Obj_00772e40* __stdcall wrap_00772e40(void*); extern "C" void final_00772e40(void*);
void func_00772e40() { void* local; reg_00772e40((void*)0x58dd70,(void*)0x8c37bc); local=make_00772e40(); Obj_00772e40* o=wrap_00772e40(&local)->get(); *(void**)o=(void*)0x8a4508; final_00772e40((void*)0x77ae40); }
