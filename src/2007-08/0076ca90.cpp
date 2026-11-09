// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ca90 { Obj_0076ca90* get(); }; extern "C" void reg_0076ca90(void*,void*); extern "C" void* make_0076ca90(); extern "C" Obj_0076ca90* __stdcall wrap_0076ca90(void*); extern "C" void final_0076ca90(void*);
void func_0076ca90() { void* local; reg_0076ca90((void*)0x414210,(void*)0x8bb218); local=make_0076ca90(); Obj_0076ca90* o=wrap_0076ca90(&local)->get(); *(void**)o=(void*)0x8846b8; final_0076ca90((void*)0x777550); }
