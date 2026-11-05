// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076dd40 { Obj_0076dd40* get(); }; extern "C" void reg_0076dd40(void*,void*); extern "C" void* make_0076dd40(); extern "C" Obj_0076dd40* __stdcall wrap_0076dd40(void*); extern "C" void final_0076dd40(void*);
void func_0076dd40() { void* local; reg_0076dd40((void*)0x41ce40,(void*)0x8b59ac); local=make_0076dd40(); Obj_0076dd40* o=wrap_0076dd40(&local)->get(); *(void**)o=(void*)0x883c00; final_0076dd40((void*)0x7776e0); }
