// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5ca0(const char*,int); struct Descriptor_005b5ca0{void attach(void*);}; extern Descriptor_005b5ca0 global_desc_005b5ca0; extern void register_desc_005b5ca0(void(*)()); extern int name_005b5ca0; extern int callback_impl;
struct Init_005b5ca0{Init_005b5ca0(){void* p=make_desc_005b5ca0((const char*)&name_005b5ca0,0);global_desc_005b5ca0.attach(p);register_desc_005b5ca0((void(*)())&callback_impl);}}; Init_005b5ca0* func_005b5ca0(){static Init_005b5ca0 init;return &init;}
