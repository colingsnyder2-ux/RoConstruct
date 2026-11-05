// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6250(const char*,int); struct Descriptor_005b6250{void attach(void*);}; extern Descriptor_005b6250 global_desc_005b6250; extern void register_desc_005b6250(void(*)()); extern int name_005b6250; extern int callback_impl;
struct Init_005b6250{Init_005b6250(){void* p=make_desc_005b6250((const char*)&name_005b6250,0);global_desc_005b6250.attach(p);register_desc_005b6250((void(*)())&callback_impl);}}; Init_005b6250* func_005b6250(){static Init_005b6250 init;return &init;}
