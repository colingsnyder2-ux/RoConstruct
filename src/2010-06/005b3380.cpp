// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3380(const char*,int); struct Descriptor_005b3380{void attach(void*);}; extern Descriptor_005b3380 global_desc_005b3380; extern void register_desc_005b3380(void(*)()); extern int name_005b3380; extern int callback_impl;
struct Init_005b3380{Init_005b3380(){void* p=make_desc_005b3380((const char*)&name_005b3380,0);global_desc_005b3380.attach(p);register_desc_005b3380((void(*)())&callback_impl);}}; Init_005b3380* func_005b3380(){static Init_005b3380 init;return &init;}
