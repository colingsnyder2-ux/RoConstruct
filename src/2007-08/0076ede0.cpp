// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ede0 { Obj_0076ede0* get(); }; extern "C" void reg_0076ede0(void*,void*); extern "C" void* make_0076ede0(); extern "C" Obj_0076ede0* __stdcall wrap_0076ede0(void*); extern "C" void final_0076ede0(void*);
void func_0076ede0() { void* local; reg_0076ede0((void*)0x487960,(void*)0x8bdca8); local=make_0076ede0(); Obj_0076ede0* o=wrap_0076ede0(&local)->get(); *(void**)o=(void*)0x88e30c; final_0076ede0((void*)0x7782c0); }
