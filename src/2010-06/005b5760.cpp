// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5760(const char*,int); struct Descriptor_005b5760{void attach(void*);}; extern Descriptor_005b5760 global_desc_005b5760; extern void register_desc_005b5760(void(*)()); extern int name_005b5760; extern int callback_impl;
struct Init_005b5760{Init_005b5760(){void* p=make_desc_005b5760((const char*)&name_005b5760,0);global_desc_005b5760.attach(p);register_desc_005b5760((void(*)())&callback_impl);}}; Init_005b5760* func_005b5760(){static Init_005b5760 init;return &init;}
