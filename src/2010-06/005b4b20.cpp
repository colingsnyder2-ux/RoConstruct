// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4b20(const char*,int); struct Descriptor_005b4b20{void attach(void*);}; extern Descriptor_005b4b20 global_desc_005b4b20; extern void register_desc_005b4b20(void(*)()); extern int name_005b4b20; extern int callback_impl;
struct Init_005b4b20{Init_005b4b20(){void* p=make_desc_005b4b20((const char*)&name_005b4b20,0);global_desc_005b4b20.attach(p);register_desc_005b4b20((void(*)())&callback_impl);}}; Init_005b4b20* func_005b4b20(){static Init_005b4b20 init;return &init;}
