// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775cf0 { Obj_00775cf0* get(); }; extern "C" void reg_00775cf0(void*,void*); extern "C" void* make_00775cf0(); extern "C" Obj_00775cf0* __stdcall wrap_00775cf0(void*); extern "C" void final_00775cf0(void*);
void func_00775cf0() { void* local; reg_00775cf0((void*)0x5f0c60,(void*)0x8c77f8); local=make_00775cf0(); Obj_00775cf0* o=wrap_00775cf0(&local)->get(); *(void**)o=(void*)0x8b3acc; final_00775cf0((void*)0x77c660); }
