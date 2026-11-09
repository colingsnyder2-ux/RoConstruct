// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4c00(const char*,int); struct Descriptor_005b4c00{void attach(void*);}; extern Descriptor_005b4c00 global_desc_005b4c00; extern void register_desc_005b4c00(void(*)()); extern int name_005b4c00; extern int callback_impl;
struct Init_005b4c00{Init_005b4c00(){void* p=make_desc_005b4c00((const char*)&name_005b4c00,0);global_desc_005b4c00.attach(p);register_desc_005b4c00((void(*)())&callback_impl);}}; Init_005b4c00* func_005b4c00(){static Init_005b4c00 init;return &init;}
