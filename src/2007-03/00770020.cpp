// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00770020 { Obj_00770020* get(); }; extern "C" void reg_00770020(void*,void*); extern "C" void* make_00770020(); extern "C" Obj_00770020* __stdcall wrap_00770020(void*); extern "C" void final_00770020(void*);
void func_00770020() { void* local; reg_00770020((void*)0x4858e0,(void*)0x8b8330); local=make_00770020(); Obj_00770020* o=wrap_00770020(&local)->get(); *(void**)o=(void*)0x88ce78; final_00770020((void*)0x778400); }
