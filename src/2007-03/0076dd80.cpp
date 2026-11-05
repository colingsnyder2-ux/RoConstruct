// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076dd80 { Obj_0076dd80* get(); }; extern "C" void reg_0076dd80(void*,void*); extern "C" void* make_0076dd80(); extern "C" Obj_0076dd80* __stdcall wrap_0076dd80(void*); extern "C" void final_0076dd80(void*);
void func_0076dd80() { void* local; reg_0076dd80((void*)0x41ce50,(void*)0x8b59b0); local=make_0076dd80(); Obj_0076dd80* o=wrap_0076dd80(&local)->get(); *(void**)o=(void*)0x883c04; final_0076dd80((void*)0x7776a0); }
