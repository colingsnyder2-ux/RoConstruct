// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3e70(const char*,int); struct Descriptor_005b3e70{void attach(void*);}; extern Descriptor_005b3e70 global_desc_005b3e70; extern void register_desc_005b3e70(void(*)()); extern int name_005b3e70; extern int callback_impl;
struct Init_005b3e70{Init_005b3e70(){void* p=make_desc_005b3e70((const char*)&name_005b3e70,0);global_desc_005b3e70.attach(p);register_desc_005b3e70((void(*)())&callback_impl);}}; Init_005b3e70* func_005b3e70(){static Init_005b3e70 init;return &init;}
