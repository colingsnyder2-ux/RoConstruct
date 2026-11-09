// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_007730c0 { Obj_007730c0* get(); }; extern "C" void reg_007730c0(void*,void*); extern "C" void* make_007730c0(); extern "C" Obj_007730c0* __stdcall wrap_007730c0(void*); extern "C" void final_007730c0(void*);
void func_007730c0() { void* local; reg_007730c0((void*)0x58de10,(void*)0x8c37e4); local=make_007730c0(); Obj_007730c0* o=wrap_007730c0(&local)->get(); *(void**)o=(void*)0x8a4530; final_007730c0((void*)0x77abc0); }
