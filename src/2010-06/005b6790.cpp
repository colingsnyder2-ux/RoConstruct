// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6790(const char*,int); struct Descriptor_005b6790{void attach(void*);}; extern Descriptor_005b6790 global_desc_005b6790; extern void register_desc_005b6790(void(*)()); extern int name_005b6790; extern int callback_impl;
struct Init_005b6790{Init_005b6790(){void* p=make_desc_005b6790((const char*)&name_005b6790,0);global_desc_005b6790.attach(p);register_desc_005b6790((void(*)())&callback_impl);}}; Init_005b6790* func_005b6790(){static Init_005b6790 init;return &init;}
