// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076c660 { Obj_0076c660* get(); }; extern "C" void reg_0076c660(void*,void*); extern "C" void* make_0076c660(); extern "C" Obj_0076c660* __stdcall wrap_0076c660(void*); extern "C" void final_0076c660(void*);
void func_0076c660() { void* local; reg_0076c660((void*)0x4035b0,(void*)0x8baec4); local=make_0076c660(); Obj_0076c660* o=wrap_0076c660(&local)->get(); *(void**)o=(void*)0x881368; final_0076c660((void*)0x777210); }
