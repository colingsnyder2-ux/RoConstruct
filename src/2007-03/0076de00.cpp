// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076de00 { Obj_0076de00* get(); }; extern "C" void reg_0076de00(void*,void*); extern "C" void* make_0076de00(); extern "C" Obj_0076de00* __stdcall wrap_0076de00(void*); extern "C" void final_0076de00(void*);
void func_0076de00() { void* local; reg_0076de00((void*)0x41ce70,(void*)0x8b59b8); local=make_0076de00(); Obj_0076de00* o=wrap_0076de00(&local)->get(); *(void**)o=(void*)0x883c0c; final_0076de00((void*)0x777620); }
