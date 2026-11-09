// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076dec0 { Obj_0076dec0* get(); }; extern "C" void reg_0076dec0(void*,void*); extern "C" void* make_0076dec0(); extern "C" Obj_0076dec0* __stdcall wrap_0076dec0(void*); extern "C" void final_0076dec0(void*);
void func_0076dec0() { void* local; reg_0076dec0((void*)0x422340,(void*)0x8b59fc); local=make_0076dec0(); Obj_0076dec0* o=wrap_0076dec0(&local)->get(); *(void**)o=(void*)0x885640; final_0076dec0((void*)0x777890); }
