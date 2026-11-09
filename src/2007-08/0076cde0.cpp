// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076cde0 { Obj_0076cde0* get(); }; extern "C" void reg_0076cde0(void*,void*); extern "C" void* make_0076cde0(); extern "C" Obj_0076cde0* __stdcall wrap_0076cde0(void*); extern "C" void final_0076cde0(void*);
void func_0076cde0() { void* local; reg_0076cde0((void*)0x430dc0,(void*)0x8bb92c); local=make_0076cde0(); Obj_0076cde0* o=wrap_0076cde0(&local)->get(); *(void**)o=(void*)0x886ed0; final_0076cde0((void*)0x7778f0); }
