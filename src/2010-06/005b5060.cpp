// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5060(const char*,int); struct Descriptor_005b5060{void attach(void*);}; extern Descriptor_005b5060 global_desc_005b5060; extern void register_desc_005b5060(void(*)()); extern int name_005b5060; extern int callback_impl;
struct Init_005b5060{Init_005b5060(){void* p=make_desc_005b5060((const char*)&name_005b5060,0);global_desc_005b5060.attach(p);register_desc_005b5060((void(*)())&callback_impl);}}; Init_005b5060* func_005b5060(){static Init_005b5060 init;return &init;}
