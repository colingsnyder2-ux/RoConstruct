// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076cda0 { Obj_0076cda0* get(); }; extern "C" void reg_0076cda0(void*,void*); extern "C" void* make_0076cda0(); extern "C" Obj_0076cda0* __stdcall wrap_0076cda0(void*); extern "C" void final_0076cda0(void*);
void func_0076cda0() { void* local; reg_0076cda0((void*)0x430db0,(void*)0x8bb928); local=make_0076cda0(); Obj_0076cda0* o=wrap_0076cda0(&local)->get(); *(void**)o=(void*)0x886ecc; final_0076cda0((void*)0x777930); }
