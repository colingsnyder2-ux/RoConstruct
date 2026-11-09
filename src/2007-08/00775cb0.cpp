// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775cb0 { Obj_00775cb0* get(); }; extern "C" void reg_00775cb0(void*,void*); extern "C" void* make_00775cb0(); extern "C" Obj_00775cb0* __stdcall wrap_00775cb0(void*); extern "C" void final_00775cb0(void*);
void func_00775cb0() { void* local; reg_00775cb0((void*)0x5f0c50,(void*)0x8c77f4); local=make_00775cb0(); Obj_00775cb0* o=wrap_00775cb0(&local)->get(); *(void**)o=(void*)0x8b3ac8; final_00775cb0((void*)0x77c6a0); }
