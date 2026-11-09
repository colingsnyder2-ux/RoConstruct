// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076c760 { Obj_0076c760* get(); }; extern "C" void reg_0076c760(void*,void*); extern "C" void* make_0076c760(); extern "C" Obj_0076c760* __stdcall wrap_0076c760(void*); extern "C" void final_0076c760(void*);
void func_0076c760() { void* local; reg_0076c760((void*)0x40d270,(void*)0x8baf80); local=make_0076c760(); Obj_0076c760* o=wrap_0076c760(&local)->get(); *(void**)o=(void*)0x8824c0; final_0076c760((void*)0x7773a0); }
