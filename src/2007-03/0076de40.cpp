// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076de40 { Obj_0076de40* get(); }; extern "C" void reg_0076de40(void*,void*); extern "C" void* make_0076de40(); extern "C" Obj_0076de40* __stdcall wrap_0076de40(void*); extern "C" void final_0076de40(void*);
void func_0076de40() { void* local; reg_0076de40((void*)0x422320,(void*)0x8b59f4); local=make_0076de40(); Obj_0076de40* o=wrap_0076de40(&local)->get(); *(void**)o=(void*)0x885638; final_0076de40((void*)0x777910); }
