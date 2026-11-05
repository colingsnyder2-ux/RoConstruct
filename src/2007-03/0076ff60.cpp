// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_0076ff60 { Obj_0076ff60* get(); }; extern "C" void reg_0076ff60(void*,void*); extern "C" void* make_0076ff60(); extern "C" Obj_0076ff60* __stdcall wrap_0076ff60(void*); extern "C" void final_0076ff60(void*);
void func_0076ff60() { void* local; reg_0076ff60((void*)0x4858b0,(void*)0x8b8324); local=make_0076ff60(); Obj_0076ff60* o=wrap_0076ff60(&local)->get(); *(void**)o=(void*)0x88ce6c; final_0076ff60((void*)0x7784c0); }
