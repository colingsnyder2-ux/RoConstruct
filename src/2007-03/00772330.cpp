// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00772330 { Obj_00772330* get(); }; extern "C" void reg_00772330(void*,void*); extern "C" void* make_00772330(); extern "C" Obj_00772330* __stdcall wrap_00772330(void*); extern "C" void final_00772330(void*);
void func_00772330() { void* local; reg_00772330((void*)0x555e60,(void*)0x8bc29c); local=make_00772330(); Obj_00772330* o=wrap_00772330(&local)->get(); *(void**)o=(void*)0x89dc2c; final_00772330((void*)0x779b00); }
