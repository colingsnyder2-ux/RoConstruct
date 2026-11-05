// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0040a780(const char*,int); struct Descriptor_0040a780{void attach(void*);}; extern Descriptor_0040a780 global_desc_0040a780; extern void register_desc_0040a780(void(*)()); extern int name_0040a780; extern int callback_impl;
struct Init_0040a780{Init_0040a780(){void* p=make_desc_0040a780((const char*)&name_0040a780,0);global_desc_0040a780.attach(p);register_desc_0040a780((void(*)())&callback_impl);}}; Init_0040a780* func_0040a780(){static Init_0040a780 init;return &init;}
