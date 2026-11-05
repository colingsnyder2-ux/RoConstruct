// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5c30(const char*,int); struct Descriptor_005b5c30{void attach(void*);}; extern Descriptor_005b5c30 global_desc_005b5c30; extern void register_desc_005b5c30(void(*)()); extern int name_005b5c30; extern int callback_impl;
struct Init_005b5c30{Init_005b5c30(){void* p=make_desc_005b5c30((const char*)&name_005b5c30,0);global_desc_005b5c30.attach(p);register_desc_005b5c30((void(*)())&callback_impl);}}; Init_005b5c30* func_005b5c30(){static Init_005b5c30 init;return &init;}
