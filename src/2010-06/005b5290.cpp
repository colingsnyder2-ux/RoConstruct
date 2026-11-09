// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5290(const char*,int); struct Descriptor_005b5290{void attach(void*);}; extern Descriptor_005b5290 global_desc_005b5290; extern void register_desc_005b5290(void(*)()); extern int name_005b5290; extern int callback_impl;
struct Init_005b5290{Init_005b5290(){void* p=make_desc_005b5290((const char*)&name_005b5290,0);global_desc_005b5290.attach(p);register_desc_005b5290((void(*)())&callback_impl);}}; Init_005b5290* func_005b5290(){static Init_005b5290 init;return &init;}
