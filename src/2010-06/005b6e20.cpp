// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6e20(const char*,int); struct Descriptor_005b6e20{void attach(void*);}; extern Descriptor_005b6e20 global_desc_005b6e20; extern void register_desc_005b6e20(void(*)()); extern int name_005b6e20; extern int callback_impl;
struct Init_005b6e20{Init_005b6e20(){void* p=make_desc_005b6e20((const char*)&name_005b6e20,0);global_desc_005b6e20.attach(p);register_desc_005b6e20((void(*)())&callback_impl);}}; Init_005b6e20* func_005b6e20(){static Init_005b6e20 init;return &init;}
