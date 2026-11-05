// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_007728c0 { Obj_007728c0* get(); }; extern "C" void reg_007728c0(void*,void*); extern "C" void* make_007728c0(); extern "C" Obj_007728c0* __stdcall wrap_007728c0(void*); extern "C" void final_007728c0(void*);
void func_007728c0() { void* local; reg_007728c0((void*)0x57b300,(void*)0x8c3054); local=make_007728c0(); Obj_007728c0* o=wrap_007728c0(&local)->get(); *(void**)o=(void*)0x8a21a4; final_007728c0((void*)0x77a4d0); }
