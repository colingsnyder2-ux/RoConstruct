// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ddc0 { Obj_0076ddc0* get(); }; extern "C" void reg_0076ddc0(void*,void*); extern "C" void* make_0076ddc0(); extern "C" Obj_0076ddc0* __stdcall wrap_0076ddc0(void*); extern "C" void final_0076ddc0(void*);
void func_0076ddc0() { void* local; reg_0076ddc0((void*)0x41ce60,(void*)0x8b59b4); local=make_0076ddc0(); Obj_0076ddc0* o=wrap_0076ddc0(&local)->get(); *(void**)o=(void*)0x883c08; final_0076ddc0((void*)0x777660); }
