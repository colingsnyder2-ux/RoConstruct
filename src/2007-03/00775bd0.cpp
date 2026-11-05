// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775bd0 { Obj_00775bd0* get(); }; extern "C" void reg_00775bd0(void*,void*); extern "C" void* make_00775bd0(); extern "C" Obj_00775bd0* __stdcall wrap_00775bd0(void*); extern "C" void final_00775bd0(void*);
void func_00775bd0() { void* local; reg_00775bd0((void*)0x5df0c0,(void*)0x8c07c0); local=make_00775bd0(); Obj_00775bd0* o=wrap_00775bd0(&local)->get(); *(void**)o=(void*)0x8adf84; final_00775bd0((void*)0x77bbb0); }
