// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076fa60 { Obj_0076fa60* get(); }; extern "C" void reg_0076fa60(void*,void*); extern "C" void* make_0076fa60(); extern "C" Obj_0076fa60* __stdcall wrap_0076fa60(void*); extern "C" void final_0076fa60(void*);
void func_0076fa60() { void* local; reg_0076fa60((void*)0x4a71b0,(void*)0x8be978); local=make_0076fa60(); Obj_0076fa60* o=wrap_0076fa60(&local)->get(); *(void**)o=(void*)0x892ab8; final_0076fa60((void*)0x7789a0); }
