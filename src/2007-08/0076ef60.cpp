// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ef60 { Obj_0076ef60* get(); }; extern "C" void reg_0076ef60(void*,void*); extern "C" void* make_0076ef60(); extern "C" Obj_0076ef60* __stdcall wrap_0076ef60(void*); extern "C" void final_0076ef60(void*);
void func_0076ef60() { void* local; reg_0076ef60((void*)0x4879c0,(void*)0x8bdcc0); local=make_0076ef60(); Obj_0076ef60* o=wrap_0076ef60(&local)->get(); *(void**)o=(void*)0x88e324; final_0076ef60((void*)0x778140); }
