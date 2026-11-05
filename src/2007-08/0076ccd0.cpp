// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ccd0 { Obj_0076ccd0* get(); }; extern "C" void reg_0076ccd0(void*,void*); extern "C" void* make_0076ccd0(); extern "C" Obj_0076ccd0* __stdcall wrap_0076ccd0(void*); extern "C" void final_0076ccd0(void*);
void func_0076ccd0() { void* local; reg_0076ccd0((void*)0x4206a0,(void*)0x8bb4d4); local=make_0076ccd0(); Obj_0076ccd0* o=wrap_0076ccd0(&local)->get(); *(void**)o=(void*)0x886368; final_0076ccd0((void*)0x777780); }
