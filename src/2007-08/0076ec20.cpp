// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ec20 { Obj_0076ec20* get(); }; extern "C" void reg_0076ec20(void*,void*); extern "C" void* make_0076ec20(); extern "C" Obj_0076ec20* __stdcall wrap_0076ec20(void*); extern "C" void final_0076ec20(void*);
void func_0076ec20() { void* local; reg_0076ec20((void*)0x4878f0,(void*)0x8bdc8c); local=make_0076ec20(); Obj_0076ec20* o=wrap_0076ec20(&local)->get(); *(void**)o=(void*)0x88e2f0; final_0076ec20((void*)0x778480); }
