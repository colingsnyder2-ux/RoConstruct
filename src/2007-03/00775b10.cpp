// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775b10 { Obj_00775b10* get(); }; extern "C" void reg_00775b10(void*,void*); extern "C" void* make_00775b10(); extern "C" Obj_00775b10* __stdcall wrap_00775b10(void*); extern "C" void final_00775b10(void*);
void func_00775b10() { void* local; reg_00775b10((void*)0x5df090,(void*)0x8c07b4); local=make_00775b10(); Obj_00775b10* o=wrap_00775b10(&local)->get(); *(void**)o=(void*)0x8adf78; final_00775b10((void*)0x77bc70); }
