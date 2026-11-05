// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b7050(const char*,int); struct Descriptor_005b7050{void attach(void*);}; extern Descriptor_005b7050 global_desc_005b7050; extern void register_desc_005b7050(void(*)()); extern int name_005b7050; extern int callback_impl;
struct Init_005b7050{Init_005b7050(){void* p=make_desc_005b7050((const char*)&name_005b7050,0);global_desc_005b7050.attach(p);register_desc_005b7050((void(*)())&callback_impl);}}; Init_005b7050* func_005b7050(){static Init_005b7050 init;return &init;}
