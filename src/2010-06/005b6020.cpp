// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6020(const char*,int); struct Descriptor_005b6020{void attach(void*);}; extern Descriptor_005b6020 global_desc_005b6020; extern void register_desc_005b6020(void(*)()); extern int name_005b6020; extern int callback_impl;
struct Init_005b6020{Init_005b6020(){void* p=make_desc_005b6020((const char*)&name_005b6020,0);global_desc_005b6020.attach(p);register_desc_005b6020((void(*)())&callback_impl);}}; Init_005b6020* func_005b6020(){static Init_005b6020 init;return &init;}
