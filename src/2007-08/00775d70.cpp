// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775d70 { Obj_00775d70* get(); }; extern "C" void reg_00775d70(void*,void*); extern "C" void* make_00775d70(); extern "C" Obj_00775d70* __stdcall wrap_00775d70(void*); extern "C" void final_00775d70(void*);
void func_00775d70() { void* local; reg_00775d70((void*)0x5f0c80,(void*)0x8c7800); local=make_00775d70(); Obj_00775d70* o=wrap_00775d70(&local)->get(); *(void**)o=(void*)0x8b3ad4; final_00775d70((void*)0x77c5e0); }
