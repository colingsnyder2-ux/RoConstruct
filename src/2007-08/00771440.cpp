// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00771440 { Obj_00771440* get(); }; extern "C" void reg_00771440(void*,void*); extern "C" void* make_00771440(); extern "C" Obj_00771440* __stdcall wrap_00771440(void*); extern "C" void final_00771440(void*);
void func_00771440() { void* local; reg_00771440((void*)0x5586e0,(void*)0x8c1f0c); local=make_00771440(); Obj_00771440* o=wrap_00771440(&local)->get(); *(void**)o=(void*)0x89ebc4; final_00771440((void*)0x779c40); }
