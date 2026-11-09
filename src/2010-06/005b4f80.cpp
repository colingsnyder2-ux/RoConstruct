// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4f80(const char*,int); struct Descriptor_005b4f80{void attach(void*);}; extern Descriptor_005b4f80 global_desc_005b4f80; extern void register_desc_005b4f80(void(*)()); extern int name_005b4f80; extern int callback_impl;
struct Init_005b4f80{Init_005b4f80(){void* p=make_desc_005b4f80((const char*)&name_005b4f80,0);global_desc_005b4f80.attach(p);register_desc_005b4f80((void(*)())&callback_impl);}}; Init_005b4f80* func_005b4f80(){static Init_005b4f80 init;return &init;}
