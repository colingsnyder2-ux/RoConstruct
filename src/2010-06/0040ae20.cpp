// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0040ae20(const char*,int); struct Descriptor_0040ae20{void attach(void*);}; extern Descriptor_0040ae20 global_desc_0040ae20; extern void register_desc_0040ae20(void(*)()); extern int name_0040ae20; extern int callback_impl;
struct Init_0040ae20{Init_0040ae20(){void* p=make_desc_0040ae20((const char*)&name_0040ae20,0);global_desc_0040ae20.attach(p);register_desc_0040ae20((void(*)())&callback_impl);}}; Init_0040ae20* func_0040ae20(){static Init_0040ae20 init;return &init;}
