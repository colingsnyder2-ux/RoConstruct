// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6a30(const char*,int); struct Descriptor_005b6a30{void attach(void*);}; extern Descriptor_005b6a30 global_desc_005b6a30; extern void register_desc_005b6a30(void(*)()); extern int name_005b6a30; extern int callback_impl;
struct Init_005b6a30{Init_005b6a30(){void* p=make_desc_005b6a30((const char*)&name_005b6a30,0);global_desc_005b6a30.attach(p);register_desc_005b6a30((void(*)())&callback_impl);}}; Init_005b6a30* func_005b6a30(){static Init_005b6a30 init;return &init;}
