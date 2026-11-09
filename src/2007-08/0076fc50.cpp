// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076fc50 { Obj_0076fc50* get(); }; extern "C" void reg_0076fc50(void*,void*); extern "C" void* make_0076fc50(); extern "C" Obj_0076fc50* __stdcall wrap_0076fc50(void*); extern "C" void final_0076fc50(void*);
void func_0076fc50() { void* local; reg_0076fc50((void*)0x4cd760,(void*)0x8bf9d8); local=make_0076fc50(); Obj_0076fc50* o=wrap_0076fc50(&local)->get(); *(void**)o=(void*)0x896c44; final_0076fc50((void*)0x778be0); }
