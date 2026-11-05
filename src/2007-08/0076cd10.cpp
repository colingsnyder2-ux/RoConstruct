// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076cd10 { Obj_0076cd10* get(); }; extern "C" void reg_0076cd10(void*,void*); extern "C" void* make_0076cd10(); extern "C" Obj_0076cd10* __stdcall wrap_0076cd10(void*); extern "C" void final_0076cd10(void*);
void func_0076cd10() { void* local; reg_0076cd10((void*)0x4206b0,(void*)0x8bb4d8); local=make_0076cd10(); Obj_0076cd10* o=wrap_0076cd10(&local)->get(); *(void**)o=(void*)0x88636c; final_0076cd10((void*)0x777740); }
