// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004d1420(const char*,int); struct Descriptor_004d1420{void attach(void*);}; extern Descriptor_004d1420 global_desc_004d1420; extern void register_desc_004d1420(void(*)()); extern int name_004d1420; extern int callback_impl;
struct Init_004d1420{Init_004d1420(){void* p=make_desc_004d1420((const char*)&name_004d1420,0);global_desc_004d1420.attach(p);register_desc_004d1420((void(*)())&callback_impl);}}; Init_004d1420* func_004d1420(){static Init_004d1420 init;return &init;}
