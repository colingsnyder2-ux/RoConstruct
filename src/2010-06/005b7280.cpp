// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b7280(const char*,int); struct Descriptor_005b7280{void attach(void*);}; extern Descriptor_005b7280 global_desc_005b7280; extern void register_desc_005b7280(void(*)()); extern int name_005b7280; extern int callback_impl;
struct Init_005b7280{Init_005b7280(){void* p=make_desc_005b7280((const char*)&name_005b7280,0);global_desc_005b7280.attach(p);register_desc_005b7280((void(*)())&callback_impl);}}; Init_005b7280* func_005b7280(){static Init_005b7280 init;return &init;}
