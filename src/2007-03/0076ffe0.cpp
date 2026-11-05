// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ffe0 { Obj_0076ffe0* get(); }; extern "C" void reg_0076ffe0(void*,void*); extern "C" void* make_0076ffe0(); extern "C" Obj_0076ffe0* __stdcall wrap_0076ffe0(void*); extern "C" void final_0076ffe0(void*);
void func_0076ffe0() { void* local; reg_0076ffe0((void*)0x4858d0,(void*)0x8b832c); local=make_0076ffe0(); Obj_0076ffe0* o=wrap_0076ffe0(&local)->get(); *(void**)o=(void*)0x88ce74; final_0076ffe0((void*)0x778440); }
