// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4180(const char*,int); struct Descriptor_005b4180{void attach(void*);}; extern Descriptor_005b4180 global_desc_005b4180; extern void register_desc_005b4180(void(*)()); extern int name_005b4180; extern int callback_impl;
struct Init_005b4180{Init_005b4180(){void* p=make_desc_005b4180((const char*)&name_005b4180,0);global_desc_005b4180.attach(p);register_desc_005b4180((void(*)())&callback_impl);}}; Init_005b4180* func_005b4180(){static Init_005b4180 init;return &init;}
