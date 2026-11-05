// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0040a710(const char*,int); struct Descriptor_0040a710{void attach(void*);}; extern Descriptor_0040a710 global_desc_0040a710; extern void register_desc_0040a710(void(*)()); extern int name_0040a710; extern int callback_impl;
struct Init_0040a710{Init_0040a710(){void* p=make_desc_0040a710((const char*)&name_0040a710,0);global_desc_0040a710.attach(p);register_desc_0040a710((void(*)())&callback_impl);}}; Init_0040a710* func_0040a710(){static Init_0040a710 init;return &init;}
