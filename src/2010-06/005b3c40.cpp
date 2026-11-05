// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3c40(const char*,int); struct Descriptor_005b3c40{void attach(void*);}; extern Descriptor_005b3c40 global_desc_005b3c40; extern void register_desc_005b3c40(void(*)()); extern int name_005b3c40; extern int callback_impl;
struct Init_005b3c40{Init_005b3c40(){void* p=make_desc_005b3c40((const char*)&name_005b3c40,0);global_desc_005b3c40.attach(p);register_desc_005b3c40((void(*)())&callback_impl);}}; Init_005b3c40* func_005b3c40(){static Init_005b3c40 init;return &init;}
