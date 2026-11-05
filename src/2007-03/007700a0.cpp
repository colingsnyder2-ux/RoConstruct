// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_007700a0 { Obj_007700a0* get(); }; extern "C" void reg_007700a0(void*,void*); extern "C" void* make_007700a0(); extern "C" Obj_007700a0* __stdcall wrap_007700a0(void*); extern "C" void final_007700a0(void*);
void func_007700a0() { void* local; reg_007700a0((void*)0x485900,(void*)0x8b8338); local=make_007700a0(); Obj_007700a0* o=wrap_007700a0(&local)->get(); *(void**)o=(void*)0x88ce80; final_007700a0((void*)0x778380); }
