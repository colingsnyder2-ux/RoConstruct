// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_007701e0 { Obj_007701e0* get(); }; extern "C" void reg_007701e0(void*,void*); extern "C" void* make_007701e0(); extern "C" Obj_007701e0* __stdcall wrap_007701e0(void*); extern "C" void final_007701e0(void*);
void func_007701e0() { void* local; reg_007701e0((void*)0x485950,(void*)0x8b834c); local=make_007701e0(); Obj_007701e0* o=wrap_007701e0(&local)->get(); *(void**)o=(void*)0x88ce94; final_007701e0((void*)0x778240); }
