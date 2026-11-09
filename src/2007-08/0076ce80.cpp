// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ce80 { Obj_0076ce80* get(); }; extern "C" void reg_0076ce80(void*,void*); extern "C" void* make_0076ce80(); extern "C" Obj_0076ce80* __stdcall wrap_0076ce80(void*); extern "C" void final_0076ce80(void*);
void func_0076ce80() { void* local; reg_0076ce80((void*)0x439830,(void*)0x8bb97c); local=make_0076ce80(); Obj_0076ce80* o=wrap_0076ce80(&local)->get(); *(void**)o=(void*)0x887ea4; final_0076ce80((void*)0x777a20); }
