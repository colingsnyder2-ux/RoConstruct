// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00771480 { Obj_00771480* get(); }; extern "C" void reg_00771480(void*,void*); extern "C" void* make_00771480(); extern "C" Obj_00771480* __stdcall wrap_00771480(void*); extern "C" void final_00771480(void*);
void func_00771480() { void* local; reg_00771480((void*)0x5586f0,(void*)0x8c1f10); local=make_00771480(); Obj_00771480* o=wrap_00771480(&local)->get(); *(void**)o=(void*)0x89ebc8; final_00771480((void*)0x779c00); }
