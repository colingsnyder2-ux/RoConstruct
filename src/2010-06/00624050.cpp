// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_00624050(const char*,int); struct Descriptor_00624050{void attach(void*);}; extern Descriptor_00624050 global_desc_00624050; extern void register_desc_00624050(void(*)()); extern int name_00624050; extern int callback_impl;
struct Init_00624050{Init_00624050(){void* p=make_desc_00624050((const char*)&name_00624050,0);global_desc_00624050.attach(p);register_desc_00624050((void(*)())&callback_impl);}}; Init_00624050* func_00624050(){static Init_00624050 init;return &init;}
