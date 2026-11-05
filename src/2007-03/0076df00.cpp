// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076df00 { Obj_0076df00* get(); }; extern "C" void reg_0076df00(void*,void*); extern "C" void* make_0076df00(); extern "C" Obj_0076df00* __stdcall wrap_0076df00(void*); extern "C" void final_0076df00(void*);
void func_0076df00() { void* local; reg_0076df00((void*)0x422350,(void*)0x8b5a00); local=make_0076df00(); Obj_0076df00* o=wrap_0076df00(&local)->get(); *(void**)o=(void*)0x885644; final_0076df00((void*)0x777850); }
