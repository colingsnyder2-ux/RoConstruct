// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_007700e0 { Obj_007700e0* get(); }; extern "C" void reg_007700e0(void*,void*); extern "C" void* make_007700e0(); extern "C" Obj_007700e0* __stdcall wrap_007700e0(void*); extern "C" void final_007700e0(void*);
void func_007700e0() { void* local; reg_007700e0((void*)0x485910,(void*)0x8b833c); local=make_007700e0(); Obj_007700e0* o=wrap_007700e0(&local)->get(); *(void**)o=(void*)0x88ce84; final_007700e0((void*)0x778340); }
