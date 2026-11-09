// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3700(const char*,int); struct Descriptor_005b3700{void attach(void*);}; extern Descriptor_005b3700 global_desc_005b3700; extern void register_desc_005b3700(void(*)()); extern int name_005b3700; extern int callback_impl;
struct Init_005b3700{Init_005b3700(){void* p=make_desc_005b3700((const char*)&name_005b3700,0);global_desc_005b3700.attach(p);register_desc_005b3700((void(*)())&callback_impl);}}; Init_005b3700* func_005b3700(){static Init_005b3700 init;return &init;}
