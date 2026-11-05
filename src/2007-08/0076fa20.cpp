// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076fa20 { Obj_0076fa20* get(); }; extern "C" void reg_0076fa20(void*,void*); extern "C" void* make_0076fa20(); extern "C" Obj_0076fa20* __stdcall wrap_0076fa20(void*); extern "C" void final_0076fa20(void*);
void func_0076fa20() { void* local; reg_0076fa20((void*)0x4a71a0,(void*)0x8be974); local=make_0076fa20(); Obj_0076fa20* o=wrap_0076fa20(&local)->get(); *(void**)o=(void*)0x892ab4; final_0076fa20((void*)0x7789e0); }
