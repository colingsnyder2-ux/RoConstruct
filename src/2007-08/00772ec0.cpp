// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00772ec0 { Obj_00772ec0* get(); }; extern "C" void reg_00772ec0(void*,void*); extern "C" void* make_00772ec0(); extern "C" Obj_00772ec0* __stdcall wrap_00772ec0(void*); extern "C" void final_00772ec0(void*);
void func_00772ec0() { void* local; reg_00772ec0((void*)0x58dd90,(void*)0x8c37c4); local=make_00772ec0(); Obj_00772ec0* o=wrap_00772ec0(&local)->get(); *(void**)o=(void*)0x8a4510; final_00772ec0((void*)0x77adc0); }
