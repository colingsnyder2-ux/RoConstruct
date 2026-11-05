// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_007704d0 { Obj_007704d0* get(); }; extern "C" void reg_007704d0(void*,void*); extern "C" void* make_007704d0(); extern "C" Obj_007704d0* __stdcall wrap_007704d0(void*); extern "C" void final_007704d0(void*);
void func_007704d0() { void* local; reg_007704d0((void*)0x48bf70,(void*)0x8b864c); local=make_007704d0(); Obj_007704d0* o=wrap_007704d0(&local)->get(); *(void**)o=(void*)0x88e12c; final_007704d0((void*)0x778650); }
