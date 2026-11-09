// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3310(const char*,int); struct Descriptor_005b3310{void attach(void*);}; extern Descriptor_005b3310 global_desc_005b3310; extern void register_desc_005b3310(void(*)()); extern int name_005b3310; extern int callback_impl;
struct Init_005b3310{Init_005b3310(){void* p=make_desc_005b3310((const char*)&name_005b3310,0);global_desc_005b3310.attach(p);register_desc_005b3310((void(*)())&callback_impl);}}; Init_005b3310* func_005b3310(){static Init_005b3310 init;return &init;}
