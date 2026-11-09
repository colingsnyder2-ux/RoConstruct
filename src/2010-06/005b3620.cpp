// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3620(const char*,int); struct Descriptor_005b3620{void attach(void*);}; extern Descriptor_005b3620 global_desc_005b3620; extern void register_desc_005b3620(void(*)()); extern int name_005b3620; extern int callback_impl;
struct Init_005b3620{Init_005b3620(){void* p=make_desc_005b3620((const char*)&name_005b3620,0);global_desc_005b3620.attach(p);register_desc_005b3620((void(*)())&callback_impl);}}; Init_005b3620* func_005b3620(){static Init_005b3620 init;return &init;}
