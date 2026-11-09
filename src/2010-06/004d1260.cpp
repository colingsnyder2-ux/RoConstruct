// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004d1260(const char*,int); struct Descriptor_004d1260{void attach(void*);}; extern Descriptor_004d1260 global_desc_004d1260; extern void register_desc_004d1260(void(*)()); extern int name_004d1260; extern int callback_impl;
struct Init_004d1260{Init_004d1260(){void* p=make_desc_004d1260((const char*)&name_004d1260,0);global_desc_004d1260.attach(p);register_desc_004d1260((void(*)())&callback_impl);}}; Init_004d1260* func_004d1260(){static Init_004d1260 init;return &init;}
