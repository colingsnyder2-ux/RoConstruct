// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076f270 { Obj_0076f270* get(); }; extern "C" void reg_0076f270(void*,void*); extern "C" void* make_0076f270(); extern "C" Obj_0076f270* __stdcall wrap_0076f270(void*); extern "C" void final_0076f270(void*);
void func_0076f270() { void* local; reg_0076f270((void*)0x492080,(void*)0x8bdfa4); local=make_0076f270(); Obj_0076f270* o=wrap_0076f270(&local)->get(); *(void**)o=(void*)0x88f5ac; final_0076f270((void*)0x7785f0); }
