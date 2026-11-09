// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0040b180(const char*,int); struct Descriptor_0040b180{void attach(void*);}; extern Descriptor_0040b180 global_desc_0040b180; extern void register_desc_0040b180(void(*)()); extern int name_0040b180; extern int callback_impl;
struct Init_0040b180{Init_0040b180(){void* p=make_desc_0040b180((const char*)&name_0040b180,0);global_desc_0040b180.attach(p);register_desc_0040b180((void(*)())&callback_impl);}}; Init_0040b180* func_0040b180(){static Init_0040b180 init;return &init;}
