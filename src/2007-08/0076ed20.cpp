// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ed20 { Obj_0076ed20* get(); }; extern "C" void reg_0076ed20(void*,void*); extern "C" void* make_0076ed20(); extern "C" Obj_0076ed20* __stdcall wrap_0076ed20(void*); extern "C" void final_0076ed20(void*);
void func_0076ed20() { void* local; reg_0076ed20((void*)0x487930,(void*)0x8bdc9c); local=make_0076ed20(); Obj_0076ed20* o=wrap_0076ed20(&local)->get(); *(void**)o=(void*)0x88e300; final_0076ed20((void*)0x778380); }
