// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00770160 { Obj_00770160* get(); }; extern "C" void reg_00770160(void*,void*); extern "C" void* make_00770160(); extern "C" Obj_00770160* __stdcall wrap_00770160(void*); extern "C" void final_00770160(void*);
void func_00770160() { void* local; reg_00770160((void*)0x485930,(void*)0x8b8344); local=make_00770160(); Obj_00770160* o=wrap_00770160(&local)->get(); *(void**)o=(void*)0x88ce8c; final_00770160((void*)0x7782c0); }
