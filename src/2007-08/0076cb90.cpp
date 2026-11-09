// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076cb90 { Obj_0076cb90* get(); }; extern "C" void reg_0076cb90(void*,void*); extern "C" void* make_0076cb90(); extern "C" Obj_0076cb90* __stdcall wrap_0076cb90(void*); extern "C" void final_0076cb90(void*);
void func_0076cb90() { void* local; reg_0076cb90((void*)0x41c130,(void*)0x8bb488); local=make_0076cb90(); Obj_0076cb90* o=wrap_0076cb90(&local)->get(); *(void**)o=(void*)0x884a54; final_0076cb90((void*)0x777590); }
