// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_00532d80(const char*,int); struct Descriptor_00532d80{void attach(void*);}; extern Descriptor_00532d80 global_desc_00532d80; extern void register_desc_00532d80(void(*)()); extern int name_00532d80; extern int callback_impl;
struct Init_00532d80{Init_00532d80(){void* p=make_desc_00532d80((const char*)&name_00532d80,0);global_desc_00532d80.attach(p);register_desc_00532d80((void(*)())&callback_impl);}}; Init_00532d80* func_00532d80(){static Init_00532d80 init;return &init;}
