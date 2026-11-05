// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6170(const char*,int); struct Descriptor_005b6170{void attach(void*);}; extern Descriptor_005b6170 global_desc_005b6170; extern void register_desc_005b6170(void(*)()); extern int name_005b6170; extern int callback_impl;
struct Init_005b6170{Init_005b6170(){void* p=make_desc_005b6170((const char*)&name_005b6170,0);global_desc_005b6170.attach(p);register_desc_005b6170((void(*)())&callback_impl);}}; Init_005b6170* func_005b6170(){static Init_005b6170 init;return &init;}
