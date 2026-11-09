// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0059f430(const char*,int); struct Descriptor_0059f430{void attach(void*);}; extern Descriptor_0059f430 global_desc_0059f430; extern void register_desc_0059f430(void(*)()); extern int name_0059f430; extern int callback_impl;
struct Init_0059f430{Init_0059f430(){void* p=make_desc_0059f430((const char*)&name_0059f430,0);global_desc_0059f430.attach(p);register_desc_0059f430((void(*)())&callback_impl);}}; Init_0059f430* func_0059f430(){static Init_0059f430 init;return &init;}
