// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0064a240(const char*,int); struct Descriptor_0064a240{void attach(void*);}; extern Descriptor_0064a240 global_desc_0064a240; extern void register_desc_0064a240(void(*)()); extern int name_0064a240; extern int callback_impl;
struct Init_0064a240{Init_0064a240(){void* p=make_desc_0064a240((const char*)&name_0064a240,0);global_desc_0064a240.attach(p);register_desc_0064a240((void(*)())&callback_impl);}}; Init_0064a240* func_0064a240(){static Init_0064a240 init;return &init;}
