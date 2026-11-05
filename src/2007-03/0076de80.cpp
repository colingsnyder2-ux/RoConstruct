// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076de80 { Obj_0076de80* get(); }; extern "C" void reg_0076de80(void*,void*); extern "C" void* make_0076de80(); extern "C" Obj_0076de80* __stdcall wrap_0076de80(void*); extern "C" void final_0076de80(void*);
void func_0076de80() { void* local; reg_0076de80((void*)0x422330,(void*)0x8b59f8); local=make_0076de80(); Obj_0076de80* o=wrap_0076de80(&local)->get(); *(void**)o=(void*)0x88563c; final_0076de80((void*)0x7778d0); }
