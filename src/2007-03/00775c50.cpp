// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775c50 { Obj_00775c50* get(); }; extern "C" void reg_00775c50(void*,void*); extern "C" void* make_00775c50(); extern "C" Obj_00775c50* __stdcall wrap_00775c50(void*); extern "C" void final_00775c50(void*);
void func_00775c50() { void* local; reg_00775c50((void*)0x5df0e0,(void*)0x8c07c8); local=make_00775c50(); Obj_00775c50* o=wrap_00775c50(&local)->get(); *(void**)o=(void*)0x8adf8c; final_00775c50((void*)0x77bb30); }
