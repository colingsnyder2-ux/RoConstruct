// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00772f80 { Obj_00772f80* get(); }; extern "C" void reg_00772f80(void*,void*); extern "C" void* make_00772f80(); extern "C" Obj_00772f80* __stdcall wrap_00772f80(void*); extern "C" void final_00772f80(void*);
void func_00772f80() { void* local; reg_00772f80((void*)0x58ddc0,(void*)0x8c37d0); local=make_00772f80(); Obj_00772f80* o=wrap_00772f80(&local)->get(); *(void**)o=(void*)0x8a451c; final_00772f80((void*)0x77ad00); }
