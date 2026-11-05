// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4c70(const char*,int); struct Descriptor_005b4c70{void attach(void*);}; extern Descriptor_005b4c70 global_desc_005b4c70; extern void register_desc_005b4c70(void(*)()); extern int name_005b4c70; extern int callback_impl;
struct Init_005b4c70{Init_005b4c70(){void* p=make_desc_005b4c70((const char*)&name_005b4c70,0);global_desc_005b4c70.attach(p);register_desc_005b4c70((void(*)())&callback_impl);}}; Init_005b4c70* func_005b4c70(){static Init_005b4c70 init;return &init;}
