// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00772e00 { Obj_00772e00* get(); }; extern "C" void reg_00772e00(void*,void*); extern "C" void* make_00772e00(); extern "C" Obj_00772e00* __stdcall wrap_00772e00(void*); extern "C" void final_00772e00(void*);
void func_00772e00() { void* local; reg_00772e00((void*)0x588120,(void*)0x8c34fc); local=make_00772e00(); Obj_00772e00* o=wrap_00772e00(&local)->get(); *(void**)o=(void*)0x8a357c; final_00772e00((void*)0x77a840); }
