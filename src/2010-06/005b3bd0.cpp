// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3bd0(const char*,int); struct Descriptor_005b3bd0{void attach(void*);}; extern Descriptor_005b3bd0 global_desc_005b3bd0; extern void register_desc_005b3bd0(void(*)()); extern int name_005b3bd0; extern int callback_impl;
struct Init_005b3bd0{Init_005b3bd0(){void* p=make_desc_005b3bd0((const char*)&name_005b3bd0,0);global_desc_005b3bd0.attach(p);register_desc_005b3bd0((void(*)())&callback_impl);}}; Init_005b3bd0* func_005b3bd0(){static Init_005b3bd0 init;return &init;}
