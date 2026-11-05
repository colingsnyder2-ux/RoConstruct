// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076cec0 { Obj_0076cec0* get(); }; extern "C" void reg_0076cec0(void*,void*); extern "C" void* make_0076cec0(); extern "C" Obj_0076cec0* __stdcall wrap_0076cec0(void*); extern "C" void final_0076cec0(void*);
void func_0076cec0() { void* local; reg_0076cec0((void*)0x439840,(void*)0x8bb980); local=make_0076cec0(); Obj_0076cec0* o=wrap_0076cec0(&local)->get(); *(void**)o=(void*)0x887ea8; final_0076cec0((void*)0x7779e0); }
