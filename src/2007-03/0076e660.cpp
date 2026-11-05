// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076e660 { Obj_0076e660* get(); }; extern "C" void reg_0076e660(void*,void*); extern "C" void* make_0076e660(); extern "C" Obj_0076e660* __stdcall wrap_0076e660(void*); extern "C" void final_0076e660(void*);
void func_0076e660() { void* local; reg_0076e660((void*)0x456040,(void*)0x8b6584); local=make_0076e660(); Obj_0076e660* o=wrap_0076e660(&local)->get(); *(void**)o=(void*)0x88905c; final_0076e660((void*)0x777eb0); }
