// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076f230 { Obj_0076f230* get(); }; extern "C" void reg_0076f230(void*,void*); extern "C" void* make_0076f230(); extern "C" Obj_0076f230* __stdcall wrap_0076f230(void*); extern "C" void final_0076f230(void*);
void func_0076f230() { void* local; reg_0076f230((void*)0x492070,(void*)0x8bdfa0); local=make_0076f230(); Obj_0076f230* o=wrap_0076f230(&local)->get(); *(void**)o=(void*)0x88f5a8; final_0076f230((void*)0x778630); }
