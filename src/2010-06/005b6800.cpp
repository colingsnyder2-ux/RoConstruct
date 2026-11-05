// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6800(const char*,int); struct Descriptor_005b6800{void attach(void*);}; extern Descriptor_005b6800 global_desc_005b6800; extern void register_desc_005b6800(void(*)()); extern int name_005b6800; extern int callback_impl;
struct Init_005b6800{Init_005b6800(){void* p=make_desc_005b6800((const char*)&name_005b6800,0);global_desc_005b6800.attach(p);register_desc_005b6800((void(*)())&callback_impl);}}; Init_005b6800* func_005b6800(){static Init_005b6800 init;return &init;}
