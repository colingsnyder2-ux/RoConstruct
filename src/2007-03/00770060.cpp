// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00770060 { Obj_00770060* get(); }; extern "C" void reg_00770060(void*,void*); extern "C" void* make_00770060(); extern "C" Obj_00770060* __stdcall wrap_00770060(void*); extern "C" void final_00770060(void*);
void func_00770060() { void* local; reg_00770060((void*)0x4858f0,(void*)0x8b8334); local=make_00770060(); Obj_00770060* o=wrap_00770060(&local)->get(); *(void**)o=(void*)0x88ce7c; final_00770060((void*)0x7783c0); }
