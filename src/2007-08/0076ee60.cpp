// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ee60 { Obj_0076ee60* get(); }; extern "C" void reg_0076ee60(void*,void*); extern "C" void* make_0076ee60(); extern "C" Obj_0076ee60* __stdcall wrap_0076ee60(void*); extern "C" void final_0076ee60(void*);
void func_0076ee60() { void* local; reg_0076ee60((void*)0x487980,(void*)0x8bdcb0); local=make_0076ee60(); Obj_0076ee60* o=wrap_0076ee60(&local)->get(); *(void**)o=(void*)0x88e314; final_0076ee60((void*)0x778240); }
