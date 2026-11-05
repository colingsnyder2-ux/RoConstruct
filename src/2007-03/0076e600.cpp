// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076e600 { Obj_0076e600* get(); }; extern "C" void reg_0076e600(void*,void*); extern "C" void* make_0076e600(); extern "C" Obj_0076e600* __stdcall wrap_0076e600(void*); extern "C" void final_0076e600(void*);
void func_0076e600() { void* local; reg_0076e600((void*)0x44ca70,(void*)0x8b649c); local=make_0076e600(); Obj_0076e600* o=wrap_0076e600(&local)->get(); *(void**)o=(void*)0x888278; final_0076e600((void*)0x777e00); }
