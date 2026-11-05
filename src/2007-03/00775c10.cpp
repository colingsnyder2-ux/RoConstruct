// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775c10 { Obj_00775c10* get(); }; extern "C" void reg_00775c10(void*,void*); extern "C" void* make_00775c10(); extern "C" Obj_00775c10* __stdcall wrap_00775c10(void*); extern "C" void final_00775c10(void*);
void func_00775c10() { void* local; reg_00775c10((void*)0x5df0d0,(void*)0x8c07c4); local=make_00775c10(); Obj_00775c10* o=wrap_00775c10(&local)->get(); *(void**)o=(void*)0x8adf88; final_00775c10((void*)0x77bb70); }
