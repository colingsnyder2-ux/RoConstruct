// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_007701a0 { Obj_007701a0* get(); }; extern "C" void reg_007701a0(void*,void*); extern "C" void* make_007701a0(); extern "C" Obj_007701a0* __stdcall wrap_007701a0(void*); extern "C" void final_007701a0(void*);
void func_007701a0() { void* local; reg_007701a0((void*)0x485940,(void*)0x8b8348); local=make_007701a0(); Obj_007701a0* o=wrap_007701a0(&local)->get(); *(void**)o=(void*)0x88ce90; final_007701a0((void*)0x778280); }
