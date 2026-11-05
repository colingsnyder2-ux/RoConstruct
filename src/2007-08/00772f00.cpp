// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00772f00 { Obj_00772f00* get(); }; extern "C" void reg_00772f00(void*,void*); extern "C" void* make_00772f00(); extern "C" Obj_00772f00* __stdcall wrap_00772f00(void*); extern "C" void final_00772f00(void*);
void func_00772f00() { void* local; reg_00772f00((void*)0x58dda0,(void*)0x8c37c8); local=make_00772f00(); Obj_00772f00* o=wrap_00772f00(&local)->get(); *(void**)o=(void*)0x8a4514; final_00772f00((void*)0x77ad80); }
