// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00771a60 { Obj_00771a60* get(); }; extern "C" void reg_00771a60(void*,void*); extern "C" void* make_00771a60(); extern "C" Obj_00771a60* __stdcall wrap_00771a60(void*); extern "C" void final_00771a60(void*);
void func_00771a60() { void* local; reg_00771a60((void*)0x55ed60,(void*)0x8c2324); local=make_00771a60(); Obj_00771a60* o=wrap_00771a60(&local)->get(); *(void**)o=(void*)0x89f380; final_00771a60((void*)0x779d00); }
