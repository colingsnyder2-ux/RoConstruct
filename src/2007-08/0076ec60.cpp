// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ec60 { Obj_0076ec60* get(); }; extern "C" void reg_0076ec60(void*,void*); extern "C" void* make_0076ec60(); extern "C" Obj_0076ec60* __stdcall wrap_0076ec60(void*); extern "C" void final_0076ec60(void*);
void func_0076ec60() { void* local; reg_0076ec60((void*)0x487900,(void*)0x8bdc90); local=make_0076ec60(); Obj_0076ec60* o=wrap_0076ec60(&local)->get(); *(void**)o=(void*)0x88e2f4; final_0076ec60((void*)0x778440); }
