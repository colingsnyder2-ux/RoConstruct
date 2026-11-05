// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6c60(const char*,int); struct Descriptor_005b6c60{void attach(void*);}; extern Descriptor_005b6c60 global_desc_005b6c60; extern void register_desc_005b6c60(void(*)()); extern int name_005b6c60; extern int callback_impl;
struct Init_005b6c60{Init_005b6c60(){void* p=make_desc_005b6c60((const char*)&name_005b6c60,0);global_desc_005b6c60.attach(p);register_desc_005b6c60((void(*)())&callback_impl);}}; Init_005b6c60* func_005b6c60(){static Init_005b6c60 init;return &init;}
