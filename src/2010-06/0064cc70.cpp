// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0064cc70(const char*,int); struct Descriptor_0064cc70{void attach(void*);}; extern Descriptor_0064cc70 global_desc_0064cc70; extern void register_desc_0064cc70(void(*)()); extern int name_0064cc70; extern int callback_impl;
struct Init_0064cc70{Init_0064cc70(){void* p=make_desc_0064cc70((const char*)&name_0064cc70,0);global_desc_0064cc70.attach(p);register_desc_0064cc70((void(*)())&callback_impl);}}; Init_0064cc70* func_0064cc70(){static Init_0064cc70 init;return &init;}
