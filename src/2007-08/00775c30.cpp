// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775c30 { Obj_00775c30* get(); }; extern "C" void reg_00775c30(void*,void*); extern "C" void* make_00775c30(); extern "C" Obj_00775c30* __stdcall wrap_00775c30(void*); extern "C" void final_00775c30(void*);
void func_00775c30() { void* local; reg_00775c30((void*)0x5f0c30,(void*)0x8c77ec); local=make_00775c30(); Obj_00775c30* o=wrap_00775c30(&local)->get(); *(void**)o=(void*)0x8b3ac0; final_00775c30((void*)0x77c720); }
