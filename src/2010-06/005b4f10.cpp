// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4f10(const char*,int); struct Descriptor_005b4f10{void attach(void*);}; extern Descriptor_005b4f10 global_desc_005b4f10; extern void register_desc_005b4f10(void(*)()); extern int name_005b4f10; extern int callback_impl;
struct Init_005b4f10{Init_005b4f10(){void* p=make_desc_005b4f10((const char*)&name_005b4f10,0);global_desc_005b4f10.attach(p);register_desc_005b4f10((void(*)())&callback_impl);}}; Init_005b4f10* func_005b4f10(){static Init_005b4f10 init;return &init;}
