// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4730(const char*,int); struct Descriptor_005b4730{void attach(void*);}; extern Descriptor_005b4730 global_desc_005b4730; extern void register_desc_005b4730(void(*)()); extern int name_005b4730; extern int callback_impl;
struct Init_005b4730{Init_005b4730(){void* p=make_desc_005b4730((const char*)&name_005b4730,0);global_desc_005b4730.attach(p);register_desc_005b4730((void(*)())&callback_impl);}}; Init_005b4730* func_005b4730(){static Init_005b4730 init;return &init;}
