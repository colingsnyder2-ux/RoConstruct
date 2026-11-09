// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3770(const char*,int); struct Descriptor_005b3770{void attach(void*);}; extern Descriptor_005b3770 global_desc_005b3770; extern void register_desc_005b3770(void(*)()); extern int name_005b3770; extern int callback_impl;
struct Init_005b3770{Init_005b3770(){void* p=make_desc_005b3770((const char*)&name_005b3770,0);global_desc_005b3770.attach(p);register_desc_005b3770((void(*)())&callback_impl);}}; Init_005b3770* func_005b3770(){static Init_005b3770 init;return &init;}
