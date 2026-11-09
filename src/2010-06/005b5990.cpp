// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5990(const char*,int); struct Descriptor_005b5990{void attach(void*);}; extern Descriptor_005b5990 global_desc_005b5990; extern void register_desc_005b5990(void(*)()); extern int name_005b5990; extern int callback_impl;
struct Init_005b5990{Init_005b5990(){void* p=make_desc_005b5990((const char*)&name_005b5990,0);global_desc_005b5990.attach(p);register_desc_005b5990((void(*)())&callback_impl);}}; Init_005b5990* func_005b5990(){static Init_005b5990 init;return &init;}
