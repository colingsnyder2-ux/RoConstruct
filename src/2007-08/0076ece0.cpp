// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ece0 { Obj_0076ece0* get(); }; extern "C" void reg_0076ece0(void*,void*); extern "C" void* make_0076ece0(); extern "C" Obj_0076ece0* __stdcall wrap_0076ece0(void*); extern "C" void final_0076ece0(void*);
void func_0076ece0() { void* local; reg_0076ece0((void*)0x487920,(void*)0x8bdc98); local=make_0076ece0(); Obj_0076ece0* o=wrap_0076ece0(&local)->get(); *(void**)o=(void*)0x88e2fc; final_0076ece0((void*)0x7783c0); }
