// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076da50 { Obj_0076da50* get(); }; extern "C" void reg_0076da50(void*,void*); extern "C" void* make_0076da50(); extern "C" Obj_0076da50* __stdcall wrap_0076da50(void*); extern "C" void final_0076da50(void*);
void func_0076da50() { void* local; reg_0076da50((void*)0x40fd50,(void*)0x8b54d0); local=make_0076da50(); Obj_0076da50* o=wrap_0076da50(&local)->get(); *(void**)o=(void*)0x881754; final_0076da50((void*)0x777470); }
