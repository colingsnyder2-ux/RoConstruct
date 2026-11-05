// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00770120 { Obj_00770120* get(); }; extern "C" void reg_00770120(void*,void*); extern "C" void* make_00770120(); extern "C" Obj_00770120* __stdcall wrap_00770120(void*); extern "C" void final_00770120(void*);
void func_00770120() { void* local; reg_00770120((void*)0x485920,(void*)0x8b8340); local=make_00770120(); Obj_00770120* o=wrap_00770120(&local)->get(); *(void**)o=(void*)0x88ce88; final_00770120((void*)0x778300); }
