// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ee20 { Obj_0076ee20* get(); }; extern "C" void reg_0076ee20(void*,void*); extern "C" void* make_0076ee20(); extern "C" Obj_0076ee20* __stdcall wrap_0076ee20(void*); extern "C" void final_0076ee20(void*);
void func_0076ee20() { void* local; reg_0076ee20((void*)0x487970,(void*)0x8bdcac); local=make_0076ee20(); Obj_0076ee20* o=wrap_0076ee20(&local)->get(); *(void**)o=(void*)0x88e310; final_0076ee20((void*)0x778280); }
