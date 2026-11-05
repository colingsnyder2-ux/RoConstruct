// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6090(const char*,int); struct Descriptor_005b6090{void attach(void*);}; extern Descriptor_005b6090 global_desc_005b6090; extern void register_desc_005b6090(void(*)()); extern int name_005b6090; extern int callback_impl;
struct Init_005b6090{Init_005b6090(){void* p=make_desc_005b6090((const char*)&name_005b6090,0);global_desc_005b6090.attach(p);register_desc_005b6090((void(*)())&callback_impl);}}; Init_005b6090* func_005b6090(){static Init_005b6090 init;return &init;}
