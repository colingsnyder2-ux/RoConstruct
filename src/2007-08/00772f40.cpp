// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00772f40 { Obj_00772f40* get(); }; extern "C" void reg_00772f40(void*,void*); extern "C" void* make_00772f40(); extern "C" Obj_00772f40* __stdcall wrap_00772f40(void*); extern "C" void final_00772f40(void*);
void func_00772f40() { void* local; reg_00772f40((void*)0x58ddb0,(void*)0x8c37cc); local=make_00772f40(); Obj_00772f40* o=wrap_00772f40(&local)->get(); *(void**)o=(void*)0x8a4518; final_00772f40((void*)0x77ad40); }
