// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3230(const char*,int); struct Descriptor_005b3230{void attach(void*);}; extern Descriptor_005b3230 global_desc_005b3230; extern void register_desc_005b3230(void(*)()); extern int name_005b3230; extern int callback_impl;
struct Init_005b3230{Init_005b3230(){void* p=make_desc_005b3230((const char*)&name_005b3230,0);global_desc_005b3230.attach(p);register_desc_005b3230((void(*)())&callback_impl);}}; Init_005b3230* func_005b3230(){static Init_005b3230 init;return &init;}
