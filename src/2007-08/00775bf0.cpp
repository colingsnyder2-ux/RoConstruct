// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775bf0 { Obj_00775bf0* get(); }; extern "C" void reg_00775bf0(void*,void*); extern "C" void* make_00775bf0(); extern "C" Obj_00775bf0* __stdcall wrap_00775bf0(void*); extern "C" void final_00775bf0(void*);
void func_00775bf0() { void* local; reg_00775bf0((void*)0x5f0c20,(void*)0x8c77e8); local=make_00775bf0(); Obj_00775bf0* o=wrap_00775bf0(&local)->get(); *(void**)o=(void*)0x8b3abc; final_00775bf0((void*)0x77c760); }
