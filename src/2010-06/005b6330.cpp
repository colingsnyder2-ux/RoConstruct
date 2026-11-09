// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6330(const char*,int); struct Descriptor_005b6330{void attach(void*);}; extern Descriptor_005b6330 global_desc_005b6330; extern void register_desc_005b6330(void(*)()); extern int name_005b6330; extern int callback_impl;
struct Init_005b6330{Init_005b6330(){void* p=make_desc_005b6330("LocalWorkspace",2);global_desc_005b6330.attach(p);register_desc_005b6330((void(*)())&callback_impl);}}; Init_005b6330* func_005b6330(){static Init_005b6330 init;return &init;}

