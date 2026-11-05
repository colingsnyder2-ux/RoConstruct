// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076da10 { Obj_0076da10* get(); }; extern "C" void reg_0076da10(void*,void*); extern "C" void* make_0076da10(); extern "C" Obj_0076da10* __stdcall wrap_0076da10(void*); extern "C" void final_0076da10(void*);
void func_0076da10() { void* local; reg_0076da10((void*)0x40e300,(void*)0x8b54b4); local=make_0076da10(); Obj_0076da10* o=wrap_0076da10(&local)->get(); *(void**)o=(void*)0x8815fc; final_0076da10((void*)0x7773f0); }
