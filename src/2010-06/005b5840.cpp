// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5840(const char*,int); struct Descriptor_005b5840{void attach(void*);}; extern Descriptor_005b5840 global_desc_005b5840; extern void register_desc_005b5840(void(*)()); extern int name_005b5840; extern int callback_impl;
struct Init_005b5840{Init_005b5840(){void* p=make_desc_005b5840((const char*)&name_005b5840,0);global_desc_005b5840.attach(p);register_desc_005b5840((void(*)())&callback_impl);}}; Init_005b5840* func_005b5840(){static Init_005b5840 init;return &init;}
