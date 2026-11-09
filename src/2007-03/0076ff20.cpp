// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ff20 { Obj_0076ff20* get(); }; extern "C" void reg_0076ff20(void*,void*); extern "C" void* make_0076ff20(); extern "C" Obj_0076ff20* __stdcall wrap_0076ff20(void*); extern "C" void final_0076ff20(void*);
void func_0076ff20() { void* local; reg_0076ff20((void*)0x4858a0,(void*)0x8b8320); local=make_0076ff20(); Obj_0076ff20* o=wrap_0076ff20(&local)->get(); *(void**)o=(void*)0x88ce68; final_0076ff20((void*)0x778500); }
