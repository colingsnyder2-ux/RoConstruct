// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004d1490(const char*,int); struct Descriptor_004d1490{void attach(void*);}; extern Descriptor_004d1490 global_desc_004d1490; extern void register_desc_004d1490(void(*)()); extern int name_004d1490; extern int callback_impl;
struct Init_004d1490{Init_004d1490(){void* p=make_desc_004d1490((const char*)&name_004d1490,0);global_desc_004d1490.attach(p);register_desc_004d1490((void(*)())&callback_impl);}}; Init_004d1490* func_004d1490(){static Init_004d1490 init;return &init;}
