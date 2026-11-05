// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076d400 { Obj_0076d400* get(); }; extern "C" void reg_0076d400(void*,void*); extern "C" void* make_0076d400(); extern "C" Obj_0076d400* __stdcall wrap_0076d400(void*); extern "C" void final_0076d400(void*);
void func_0076d400() { void* local; reg_0076d400((void*)0x458660,(void*)0x8bbfcc); local=make_0076d400(); Obj_0076d400* o=wrap_0076d400(&local)->get(); *(void**)o=(void*)0x88a474; final_0076d400((void*)0x777e80); }
