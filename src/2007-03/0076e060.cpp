// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076e060 { Obj_0076e060* get(); }; extern "C" void reg_0076e060(void*,void*); extern "C" void* make_0076e060(); extern "C" Obj_0076e060* __stdcall wrap_0076e060(void*); extern "C" void final_0076e060(void*);
void func_0076e060() { void* local; reg_0076e060((void*)0x4396e0,(void*)0x8b5e88); local=make_0076e060(); Obj_0076e060* o=wrap_0076e060(&local)->get(); *(void**)o=(void*)0x886d7c; final_0076e060((void*)0x777a10); }
