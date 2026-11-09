// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775b90 { Obj_00775b90* get(); }; extern "C" void reg_00775b90(void*,void*); extern "C" void* make_00775b90(); extern "C" Obj_00775b90* __stdcall wrap_00775b90(void*); extern "C" void final_00775b90(void*);
void func_00775b90() { void* local; reg_00775b90((void*)0x5df0b0,(void*)0x8c07bc); local=make_00775b90(); Obj_00775b90* o=wrap_00775b90(&local)->get(); *(void**)o=(void*)0x8adf80; final_00775b90((void*)0x77bbf0); }
