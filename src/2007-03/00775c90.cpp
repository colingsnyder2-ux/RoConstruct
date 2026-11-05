// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775c90 { Obj_00775c90* get(); }; extern "C" void reg_00775c90(void*,void*); extern "C" void* make_00775c90(); extern "C" Obj_00775c90* __stdcall wrap_00775c90(void*); extern "C" void final_00775c90(void*);
void func_00775c90() { void* local; reg_00775c90((void*)0x5df0f0,(void*)0x8c07cc); local=make_00775c90(); Obj_00775c90* o=wrap_00775c90(&local)->get(); *(void**)o=(void*)0x8adf90; final_00775c90((void*)0x77baf0); }
