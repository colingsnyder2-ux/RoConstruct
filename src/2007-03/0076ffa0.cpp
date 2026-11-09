// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ffa0 { Obj_0076ffa0* get(); }; extern "C" void reg_0076ffa0(void*,void*); extern "C" void* make_0076ffa0(); extern "C" Obj_0076ffa0* __stdcall wrap_0076ffa0(void*); extern "C" void final_0076ffa0(void*);
void func_0076ffa0() { void* local; reg_0076ffa0((void*)0x4858c0,(void*)0x8b8328); local=make_0076ffa0(); Obj_0076ffa0* o=wrap_0076ffa0(&local)->get(); *(void**)o=(void*)0x88ce70; final_0076ffa0((void*)0x778480); }
