// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b7600(const char*,int); struct Descriptor_005b7600{void attach(void*);}; extern Descriptor_005b7600 global_desc_005b7600; extern void register_desc_005b7600(void(*)()); extern int name_005b7600; extern int callback_impl;
struct Init_005b7600{Init_005b7600(){void* p=make_desc_005b7600((const char*)&name_005b7600,0);global_desc_005b7600.attach(p);register_desc_005b7600((void(*)())&callback_impl);}}; Init_005b7600* func_005b7600(){static Init_005b7600 init;return &init;}
