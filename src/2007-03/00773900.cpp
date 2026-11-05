// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00773900 { Obj_00773900* get(); }; extern "C" void reg_00773900(void*,void*); extern "C" void* make_00773900(); extern "C" Obj_00773900* __stdcall wrap_00773900(void*); extern "C" void final_00773900(void*);
void func_00773900() { void* local; reg_00773900((void*)0x588350,(void*)0x8bd84c); local=make_00773900(); Obj_00773900* o=wrap_00773900(&local)->get(); *(void**)o=(void*)0x8a1cd8; final_00773900((void*)0x77a810); }
