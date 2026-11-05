// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6560(const char*,int); struct Descriptor_005b6560{void attach(void*);}; extern Descriptor_005b6560 global_desc_005b6560; extern void register_desc_005b6560(void(*)()); extern int name_005b6560; extern int callback_impl;
struct Init_005b6560{Init_005b6560(){void* p=make_desc_005b6560((const char*)&name_005b6560,0);global_desc_005b6560.attach(p);register_desc_005b6560((void(*)())&callback_impl);}}; Init_005b6560* func_005b6560(){static Init_005b6560 init;return &init;}
