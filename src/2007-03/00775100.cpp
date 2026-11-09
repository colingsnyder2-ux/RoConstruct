// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775100 { Obj_00775100* get(); }; extern "C" void reg_00775100(void*,void*); extern "C" void* make_00775100(); extern "C" Obj_00775100* __stdcall wrap_00775100(void*); extern "C" void final_00775100(void*);
void func_00775100() { void* local; reg_00775100((void*)0x5cbfc0,(void*)0x8bffc8); local=make_00775100(); Obj_00775100* o=wrap_00775100(&local)->get(); *(void**)o=(void*)0x8a8740; final_00775100((void*)0x77b560); }
