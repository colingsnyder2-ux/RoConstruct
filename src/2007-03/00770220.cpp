// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00770220 { Obj_00770220* get(); }; extern "C" void reg_00770220(void*,void*); extern "C" void* make_00770220(); extern "C" Obj_00770220* __stdcall wrap_00770220(void*); extern "C" void final_00770220(void*);
void func_00770220() { void* local; reg_00770220((void*)0x485960,(void*)0x8b8350); local=make_00770220(); Obj_00770220* o=wrap_00770220(&local)->get(); *(void**)o=(void*)0x88ce98; final_00770220((void*)0x778200); }
