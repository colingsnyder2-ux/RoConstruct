// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076cc90 { Obj_0076cc90* get(); }; extern "C" void reg_0076cc90(void*,void*); extern "C" void* make_0076cc90(); extern "C" Obj_0076cc90* __stdcall wrap_0076cc90(void*); extern "C" void final_0076cc90(void*);
void func_0076cc90() { void* local; reg_0076cc90((void*)0x420690,(void*)0x8bb4d0); local=make_0076cc90(); Obj_0076cc90* o=wrap_0076cc90(&local)->get(); *(void**)o=(void*)0x886364; final_0076cc90((void*)0x7777c0); }
