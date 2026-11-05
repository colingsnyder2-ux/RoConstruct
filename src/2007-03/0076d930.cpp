// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076d930 { Obj_0076d930* get(); }; extern "C" void reg_0076d930(void*,void*); extern "C" void* make_0076d930(); extern "C" Obj_0076d930* __stdcall wrap_0076d930(void*); extern "C" void final_0076d930(void*);
void func_0076d930() { void* local; reg_0076d930((void*)0x4034f0,(void*)0x8b53e4); local=make_0076d930(); Obj_0076d930* o=wrap_0076d930(&local)->get(); *(void**)o=(void*)0x880370; final_0076d930((void*)0x777210); }
