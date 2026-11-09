// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076c620 { Obj_0076c620* get(); }; extern "C" void reg_0076c620(void*,void*); extern "C" void* make_0076c620(); extern "C" Obj_0076c620* __stdcall wrap_0076c620(void*); extern "C" void final_0076c620(void*);
void func_0076c620() { void* local; reg_0076c620((void*)0x4035a0,(void*)0x8baec0); local=make_0076c620(); Obj_0076c620* o=wrap_0076c620(&local)->get(); *(void**)o=(void*)0x881364; final_0076c620((void*)0x777250); }
