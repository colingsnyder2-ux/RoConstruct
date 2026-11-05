// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0040bc10(const char*,int); struct Descriptor_0040bc10{void attach(void*);}; extern Descriptor_0040bc10 global_desc_0040bc10; extern void register_desc_0040bc10(void(*)()); extern int name_0040bc10; extern int callback_impl;
struct Init_0040bc10{Init_0040bc10(){void* p=make_desc_0040bc10((const char*)&name_0040bc10,0);global_desc_0040bc10.attach(p);register_desc_0040bc10((void(*)())&callback_impl);}}; Init_0040bc10* func_0040bc10(){static Init_0040bc10 init;return &init;}
