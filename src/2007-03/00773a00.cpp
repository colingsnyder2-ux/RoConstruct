// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00773a00 { Obj_00773a00* get(); }; extern "C" void reg_00773a00(void*,void*); extern "C" void* make_00773a00(); extern "C" Obj_00773a00* __stdcall wrap_00773a00(void*); extern "C" void final_00773a00(void*);
void func_00773a00() { void* local; reg_00773a00((void*)0x588390,(void*)0x8bd85c); local=make_00773a00(); Obj_00773a00* o=wrap_00773a00(&local)->get(); *(void**)o=(void*)0x8a1ce8; final_00773a00((void*)0x77a710); }
