// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076cc10 { Obj_0076cc10* get(); }; extern "C" void reg_0076cc10(void*,void*); extern "C" void* make_0076cc10(); extern "C" Obj_0076cc10* __stdcall wrap_0076cc10(void*); extern "C" void final_0076cc10(void*);
void func_0076cc10() { void* local; reg_0076cc10((void*)0x420670,(void*)0x8bb4c8); local=make_0076cc10(); Obj_0076cc10* o=wrap_0076cc10(&local)->get(); *(void**)o=(void*)0x88635c; final_0076cc10((void*)0x777840); }
