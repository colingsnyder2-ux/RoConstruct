// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6b10(const char*,int); struct Descriptor_005b6b10{void attach(void*);}; extern Descriptor_005b6b10 global_desc_005b6b10; extern void register_desc_005b6b10(void(*)()); extern int name_005b6b10; extern int callback_impl;
struct Init_005b6b10{Init_005b6b10(){void* p=make_desc_005b6b10((const char*)&name_005b6b10,0);global_desc_005b6b10.attach(p);register_desc_005b6b10((void(*)())&callback_impl);}}; Init_005b6b10* func_005b6b10(){static Init_005b6b10 init;return &init;}
