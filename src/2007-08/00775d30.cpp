// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00775d30 { Obj_00775d30* get(); }; extern "C" void reg_00775d30(void*,void*); extern "C" void* make_00775d30(); extern "C" Obj_00775d30* __stdcall wrap_00775d30(void*); extern "C" void final_00775d30(void*);
void func_00775d30() { void* local; reg_00775d30((void*)0x5f0c70,(void*)0x8c77fc); local=make_00775d30(); Obj_00775d30* o=wrap_00775d30(&local)->get(); *(void**)o=(void*)0x8b3ad0; final_00775d30((void*)0x77c620); }
