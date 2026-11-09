// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076cd50 { Obj_0076cd50* get(); }; extern "C" void reg_0076cd50(void*,void*); extern "C" void* make_0076cd50(); extern "C" Obj_0076cd50* __stdcall wrap_0076cd50(void*); extern "C" void final_0076cd50(void*);
void func_0076cd50() { void* local; reg_0076cd50((void*)0x4206c0,(void*)0x8bb4dc); local=make_0076cd50(); Obj_0076cd50* o=wrap_0076cd50(&local)->get(); *(void**)o=(void*)0x886370; final_0076cd50((void*)0x777700); }
