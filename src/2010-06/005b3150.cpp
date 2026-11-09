// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3150(const char*,int); struct Descriptor_005b3150{void attach(void*);}; extern Descriptor_005b3150 global_desc_005b3150; extern void register_desc_005b3150(void(*)()); extern int name_005b3150; extern int callback_impl;
struct Init_005b3150{Init_005b3150(){void* p=make_desc_005b3150((const char*)&name_005b3150,0);global_desc_005b3150.attach(p);register_desc_005b3150((void(*)())&callback_impl);}}; Init_005b3150* func_005b3150(){static Init_005b3150 init;return &init;}
