// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076df80 { Obj_0076df80* get(); }; extern "C" void reg_0076df80(void*,void*); extern "C" void* make_0076df80(); extern "C" Obj_0076df80* __stdcall wrap_0076df80(void*); extern "C" void final_0076df80(void*);
void func_0076df80() { void* local; reg_0076df80((void*)0x422370,(void*)0x8b5a08); local=make_0076df80(); Obj_0076df80* o=wrap_0076df80(&local)->get(); *(void**)o=(void*)0x88564c; final_0076df80((void*)0x7777d0); }
