// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00771a20 { Obj_00771a20* get(); }; extern "C" void reg_00771a20(void*,void*); extern "C" void* make_00771a20(); extern "C" Obj_00771a20* __stdcall wrap_00771a20(void*); extern "C" void final_00771a20(void*);
void func_00771a20() { void* local; reg_00771a20((void*)0x55ed50,(void*)0x8c2320); local=make_00771a20(); Obj_00771a20* o=wrap_00771a20(&local)->get(); *(void**)o=(void*)0x89f37c; final_00771a20((void*)0x779d40); }
