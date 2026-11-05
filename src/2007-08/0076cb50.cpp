// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076cb50 { Obj_0076cb50* get(); }; extern "C" void reg_0076cb50(void*,void*); extern "C" void* make_0076cb50(); extern "C" Obj_0076cb50* __stdcall wrap_0076cb50(void*); extern "C" void final_0076cb50(void*);
void func_0076cb50() { void* local; reg_0076cb50((void*)0x41c120,(void*)0x8bb484); local=make_0076cb50(); Obj_0076cb50* o=wrap_0076cb50(&local)->get(); *(void**)o=(void*)0x884a50; final_0076cb50((void*)0x7775d0); }
