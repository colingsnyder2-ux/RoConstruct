// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076cb10 { Obj_0076cb10* get(); }; extern "C" void reg_0076cb10(void*,void*); extern "C" void* make_0076cb10(); extern "C" Obj_0076cb10* __stdcall wrap_0076cb10(void*); extern "C" void final_0076cb10(void*);
void func_0076cb10() { void* local; reg_0076cb10((void*)0x41c110,(void*)0x8bb480); local=make_0076cb10(); Obj_0076cb10* o=wrap_0076cb10(&local)->get(); *(void**)o=(void*)0x884a4c; final_0076cb10((void*)0x777610); }
