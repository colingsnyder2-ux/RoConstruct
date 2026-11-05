// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775db0 { Obj_00775db0* get(); }; extern "C" void reg_00775db0(void*,void*); extern "C" void* make_00775db0(); extern "C" Obj_00775db0* __stdcall wrap_00775db0(void*); extern "C" void final_00775db0(void*);
void func_00775db0() { void* local; reg_00775db0((void*)0x5f0c90,(void*)0x8c7804); local=make_00775db0(); Obj_00775db0* o=wrap_00775db0(&local)->get(); *(void**)o=(void*)0x8b3ad8; final_00775db0((void*)0x77c5a0); }
