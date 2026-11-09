// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076df40 { Obj_0076df40* get(); }; extern "C" void reg_0076df40(void*,void*); extern "C" void* make_0076df40(); extern "C" Obj_0076df40* __stdcall wrap_0076df40(void*); extern "C" void final_0076df40(void*);
void func_0076df40() { void* local; reg_0076df40((void*)0x422360,(void*)0x8b5a04); local=make_0076df40(); Obj_0076df40* o=wrap_0076df40(&local)->get(); *(void**)o=(void*)0x885648; final_0076df40((void*)0x777810); }
