// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3460(const char*,int); struct Descriptor_005b3460{void attach(void*);}; extern Descriptor_005b3460 global_desc_005b3460; extern void register_desc_005b3460(void(*)()); extern int name_005b3460; extern int callback_impl;
struct Init_005b3460{Init_005b3460(){void* p=make_desc_005b3460((const char*)&name_005b3460,0);global_desc_005b3460.attach(p);register_desc_005b3460((void(*)())&callback_impl);}}; Init_005b3460* func_005b3460(){static Init_005b3460 init;return &init;}
