// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b7130(const char*,int); struct Descriptor_005b7130{void attach(void*);}; extern Descriptor_005b7130 global_desc_005b7130; extern void register_desc_005b7130(void(*)()); extern int name_005b7130; extern int callback_impl;
struct Init_005b7130{Init_005b7130(){void* p=make_desc_005b7130((const char*)&name_005b7130,0);global_desc_005b7130.attach(p);register_desc_005b7130((void(*)())&callback_impl);}}; Init_005b7130* func_005b7130(){static Init_005b7130 init;return &init;}
