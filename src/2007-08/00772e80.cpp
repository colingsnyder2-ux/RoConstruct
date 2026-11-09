// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00772e80 { Obj_00772e80* get(); }; extern "C" void reg_00772e80(void*,void*); extern "C" void* make_00772e80(); extern "C" Obj_00772e80* __stdcall wrap_00772e80(void*); extern "C" void final_00772e80(void*);
void func_00772e80() { void* local; reg_00772e80((void*)0x58dd80,(void*)0x8c37c0); local=make_00772e80(); Obj_00772e80* o=wrap_00772e80(&local)->get(); *(void**)o=(void*)0x8a450c; final_00772e80((void*)0x77ae00); }
