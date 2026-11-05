// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00770bd0 { Obj_00770bd0* get(); }; extern "C" void reg_00770bd0(void*,void*); extern "C" void* make_00770bd0(); extern "C" Obj_00770bd0* __stdcall wrap_00770bd0(void*); extern "C" void final_00770bd0(void*);
void func_00770bd0() { void* local; reg_00770bd0((void*)0x49d0f0,(void*)0x8b8f2c); local=make_00770bd0(); Obj_00770bd0* o=wrap_00770bd0(&local)->get(); *(void**)o=(void*)0x890d8c; final_00770bd0((void*)0x7789c0); }
