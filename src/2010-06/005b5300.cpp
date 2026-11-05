// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5300(const char*,int); struct Descriptor_005b5300{void attach(void*);}; extern Descriptor_005b5300 global_desc_005b5300; extern void register_desc_005b5300(void(*)()); extern int name_005b5300; extern int callback_impl;
struct Init_005b5300{Init_005b5300(){void* p=make_desc_005b5300((const char*)&name_005b5300,0);global_desc_005b5300.attach(p);register_desc_005b5300((void(*)())&callback_impl);}}; Init_005b5300* func_005b5300(){static Init_005b5300 init;return &init;}
