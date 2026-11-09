// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3690(const char*,int); struct Descriptor_005b3690{void attach(void*);}; extern Descriptor_005b3690 global_desc_005b3690; extern void register_desc_005b3690(void(*)()); extern int name_005b3690; extern int callback_impl;
struct Init_005b3690{Init_005b3690(){void* p=make_desc_005b3690((const char*)&name_005b3690,0);global_desc_005b3690.attach(p);register_desc_005b3690((void(*)())&callback_impl);}}; Init_005b3690* func_005b3690(){static Init_005b3690 init;return &init;}
