// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0059ab70(const char*,int); struct Descriptor_0059ab70{void attach(void*);}; extern Descriptor_0059ab70 global_desc_0059ab70; extern void register_desc_0059ab70(void(*)()); extern int name_0059ab70; extern int callback_impl;
struct Init_0059ab70{Init_0059ab70(){void* p=make_desc_0059ab70((const char*)&name_0059ab70,0);global_desc_0059ab70.attach(p);register_desc_0059ab70((void(*)())&callback_impl);}}; Init_0059ab70* func_0059ab70(){static Init_0059ab70 init;return &init;}
