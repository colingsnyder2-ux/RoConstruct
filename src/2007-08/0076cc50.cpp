// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076cc50 { Obj_0076cc50* get(); }; extern "C" void reg_0076cc50(void*,void*); extern "C" void* make_0076cc50(); extern "C" Obj_0076cc50* __stdcall wrap_0076cc50(void*); extern "C" void final_0076cc50(void*);
void func_0076cc50() { void* local; reg_0076cc50((void*)0x420680,(void*)0x8bb4cc); local=make_0076cc50(); Obj_0076cc50* o=wrap_0076cc50(&local)->get(); *(void**)o=(void*)0x886360; final_0076cc50((void*)0x777800); }
