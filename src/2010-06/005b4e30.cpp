// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4e30(const char*,int); struct Descriptor_005b4e30{void attach(void*);}; extern Descriptor_005b4e30 global_desc_005b4e30; extern void register_desc_005b4e30(void(*)()); extern int name_005b4e30; extern int callback_impl;
struct Init_005b4e30{Init_005b4e30(){void* p=make_desc_005b4e30((const char*)&name_005b4e30,0);global_desc_005b4e30.attach(p);register_desc_005b4e30((void(*)())&callback_impl);}}; Init_005b4e30* func_005b4e30(){static Init_005b4e30 init;return &init;}
