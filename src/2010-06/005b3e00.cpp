// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3e00(const char*,int); struct Descriptor_005b3e00{void attach(void*);}; extern Descriptor_005b3e00 global_desc_005b3e00; extern void register_desc_005b3e00(void(*)()); extern int name_005b3e00; extern int callback_impl;
struct Init_005b3e00{Init_005b3e00(){void* p=make_desc_005b3e00((const char*)&name_005b3e00,0);global_desc_005b3e00.attach(p);register_desc_005b3e00((void(*)())&callback_impl);}}; Init_005b3e00* func_005b3e00(){static Init_005b3e00 init;return &init;}
