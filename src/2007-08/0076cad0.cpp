// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076cad0 { Obj_0076cad0* get(); }; extern "C" void reg_0076cad0(void*,void*); extern "C" void* make_0076cad0(); extern "C" Obj_0076cad0* __stdcall wrap_0076cad0(void*); extern "C" void final_0076cad0(void*);
void func_0076cad0() { void* local; reg_0076cad0((void*)0x41c100,(void*)0x8bb47c); local=make_0076cad0(); Obj_0076cad0* o=wrap_0076cad0(&local)->get(); *(void**)o=(void*)0x884a48; final_0076cad0((void*)0x777650); }
