// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076f960 { Obj_0076f960* get(); }; extern "C" void reg_0076f960(void*,void*); extern "C" void* make_0076f960(); extern "C" Obj_0076f960* __stdcall wrap_0076f960(void*); extern "C" void final_0076f960(void*);
void func_0076f960() { void* local; reg_0076f960((void*)0x4a7170,(void*)0x8be968); local=make_0076f960(); Obj_0076f960* o=wrap_0076f960(&local)->get(); *(void**)o=(void*)0x892aa8; final_0076f960((void*)0x778aa0); }
