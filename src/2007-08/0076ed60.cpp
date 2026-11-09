// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ed60 { Obj_0076ed60* get(); }; extern "C" void reg_0076ed60(void*,void*); extern "C" void* make_0076ed60(); extern "C" Obj_0076ed60* __stdcall wrap_0076ed60(void*); extern "C" void final_0076ed60(void*);
void func_0076ed60() { void* local; reg_0076ed60((void*)0x487940,(void*)0x8bdca0); local=make_0076ed60(); Obj_0076ed60* o=wrap_0076ed60(&local)->get(); *(void**)o=(void*)0x88e304; final_0076ed60((void*)0x778340); }
