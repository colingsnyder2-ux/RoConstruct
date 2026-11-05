// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6410(const char*,int); struct Descriptor_005b6410{void attach(void*);}; extern Descriptor_005b6410 global_desc_005b6410; extern void register_desc_005b6410(void(*)()); extern int name_005b6410; extern int callback_impl;
struct Init_005b6410{Init_005b6410(){void* p=make_desc_005b6410((const char*)&name_005b6410,0);global_desc_005b6410.attach(p);register_desc_005b6410((void(*)())&callback_impl);}}; Init_005b6410* func_005b6410(){static Init_005b6410 init;return &init;}
