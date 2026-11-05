// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076dd00 { Obj_0076dd00* get(); }; extern "C" void reg_0076dd00(void*,void*); extern "C" void* make_0076dd00(); extern "C" Obj_0076dd00* __stdcall wrap_0076dd00(void*); extern "C" void final_0076dd00(void*);
void func_0076dd00() { void* local; reg_0076dd00((void*)0x415220,(void*)0x8b5748); local=make_0076dd00(); Obj_0076dd00* o=wrap_0076dd00(&local)->get(); *(void**)o=(void*)0x883870; final_0076dd00((void*)0x7775c0); }
