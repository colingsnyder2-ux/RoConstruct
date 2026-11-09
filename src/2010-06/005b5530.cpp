// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5530(const char*,int); struct Descriptor_005b5530{void attach(void*);}; extern Descriptor_005b5530 global_desc_005b5530; extern void register_desc_005b5530(void(*)()); extern int name_005b5530; extern int callback_impl;
struct Init_005b5530{Init_005b5530(){void* p=make_desc_005b5530((const char*)&name_005b5530,0);global_desc_005b5530.attach(p);register_desc_005b5530((void(*)())&callback_impl);}}; Init_005b5530* func_005b5530(){static Init_005b5530 init;return &init;}
