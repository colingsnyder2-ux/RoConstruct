// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00772fc0 { Obj_00772fc0* get(); }; extern "C" void reg_00772fc0(void*,void*); extern "C" void* make_00772fc0(); extern "C" Obj_00772fc0* __stdcall wrap_00772fc0(void*); extern "C" void final_00772fc0(void*);
void func_00772fc0() { void* local; reg_00772fc0((void*)0x58ddd0,(void*)0x8c37d4); local=make_00772fc0(); Obj_00772fc0* o=wrap_00772fc0(&local)->get(); *(void**)o=(void*)0x8a4520; final_00772fc0((void*)0x77acc0); }
