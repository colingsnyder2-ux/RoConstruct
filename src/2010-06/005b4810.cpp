// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4810(const char*,int); struct Descriptor_005b4810{void attach(void*);}; extern Descriptor_005b4810 global_desc_005b4810; extern void register_desc_005b4810(void(*)()); extern int name_005b4810; extern int callback_impl;
struct Init_005b4810{Init_005b4810(){void* p=make_desc_005b4810((const char*)&name_005b4810,0);global_desc_005b4810.attach(p);register_desc_005b4810((void(*)())&callback_impl);}}; Init_005b4810* func_005b4810(){static Init_005b4810 init;return &init;}
