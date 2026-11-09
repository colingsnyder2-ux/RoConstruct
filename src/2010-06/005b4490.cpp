// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4490(const char*,int); struct Descriptor_005b4490{void attach(void*);}; extern Descriptor_005b4490 global_desc_005b4490; extern void register_desc_005b4490(void(*)()); extern int name_005b4490; extern int callback_impl;
struct Init_005b4490{Init_005b4490(){void* p=make_desc_005b4490((const char*)&name_005b4490,0);global_desc_005b4490.attach(p);register_desc_005b4490((void(*)())&callback_impl);}}; Init_005b4490* func_005b4490(){static Init_005b4490 init;return &init;}
