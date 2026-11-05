// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5a00(const char*,int); struct Descriptor_005b5a00{void attach(void*);}; extern Descriptor_005b5a00 global_desc_005b5a00; extern void register_desc_005b5a00(void(*)()); extern int name_005b5a00; extern int callback_impl;
struct Init_005b5a00{Init_005b5a00(){void* p=make_desc_005b5a00((const char*)&name_005b5a00,0);global_desc_005b5a00.attach(p);register_desc_005b5a00((void(*)())&callback_impl);}}; Init_005b5a00* func_005b5a00(){static Init_005b5a00 init;return &init;}
