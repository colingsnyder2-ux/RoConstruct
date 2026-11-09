// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5680(const char*,int); struct Descriptor_005b5680{void attach(void*);}; extern Descriptor_005b5680 global_desc_005b5680; extern void register_desc_005b5680(void(*)()); extern int name_005b5680; extern int callback_impl;
struct Init_005b5680{Init_005b5680(){void* p=make_desc_005b5680((const char*)&name_005b5680,0);global_desc_005b5680.attach(p);register_desc_005b5680((void(*)())&callback_impl);}}; Init_005b5680* func_005b5680(){static Init_005b5680 init;return &init;}
