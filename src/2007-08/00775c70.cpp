// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775c70 { Obj_00775c70* get(); }; extern "C" void reg_00775c70(void*,void*); extern "C" void* make_00775c70(); extern "C" Obj_00775c70* __stdcall wrap_00775c70(void*); extern "C" void final_00775c70(void*);
void func_00775c70() { void* local; reg_00775c70((void*)0x5f0c40,(void*)0x8c77f0); local=make_00775c70(); Obj_00775c70* o=wrap_00775c70(&local)->get(); *(void**)o=(void*)0x8b3ac4; final_00775c70((void*)0x77c6e0); }
