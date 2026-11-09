// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6870(const char*,int); struct Descriptor_005b6870{void attach(void*);}; extern Descriptor_005b6870 global_desc_005b6870; extern void register_desc_005b6870(void(*)()); extern int name_005b6870; extern int callback_impl;
struct Init_005b6870{Init_005b6870(){void* p=make_desc_005b6870((const char*)&name_005b6870,0);global_desc_005b6870.attach(p);register_desc_005b6870((void(*)())&callback_impl);}}; Init_005b6870* func_005b6870(){static Init_005b6870 init;return &init;}
