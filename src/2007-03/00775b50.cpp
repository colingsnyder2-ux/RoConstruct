// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775b50 { Obj_00775b50* get(); }; extern "C" void reg_00775b50(void*,void*); extern "C" void* make_00775b50(); extern "C" Obj_00775b50* __stdcall wrap_00775b50(void*); extern "C" void final_00775b50(void*);
void func_00775b50() { void* local; reg_00775b50((void*)0x5df0a0,(void*)0x8c07b8); local=make_00775b50(); Obj_00775b50* o=wrap_00775b50(&local)->get(); *(void**)o=(void*)0x8adf7c; final_00775b50((void*)0x77bc30); }
