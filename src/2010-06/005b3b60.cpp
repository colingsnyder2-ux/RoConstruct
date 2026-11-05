// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3b60(const char*,int); struct Descriptor_005b3b60{void attach(void*);}; extern Descriptor_005b3b60 global_desc_005b3b60; extern void register_desc_005b3b60(void(*)()); extern int name_005b3b60; extern int callback_impl;
struct Init_005b3b60{Init_005b3b60(){void* p=make_desc_005b3b60((const char*)&name_005b3b60,0);global_desc_005b3b60.attach(p);register_desc_005b3b60((void(*)())&callback_impl);}}; Init_005b3b60* func_005b3b60(){static Init_005b3b60 init;return &init;}
