// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076c720 { Obj_0076c720* get(); }; extern "C" void reg_0076c720(void*,void*); extern "C" void* make_0076c720(); extern "C" Obj_0076c720* __stdcall wrap_0076c720(void*); extern "C" void final_0076c720(void*);
void func_0076c720() { void* local; reg_0076c720((void*)0x408cb0,(void*)0x8baf40); local=make_0076c720(); Obj_0076c720* o=wrap_0076c720(&local)->get(); *(void**)o=(void*)0x881808; final_0076c720((void*)0x777320); }
