// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004d1570(const char*,int); struct Descriptor_004d1570{void attach(void*);}; extern Descriptor_004d1570 global_desc_004d1570; extern void register_desc_004d1570(void(*)()); extern int name_004d1570; extern int callback_impl;
struct Init_004d1570{Init_004d1570(){void* p=make_desc_004d1570((const char*)&name_004d1570,0);global_desc_004d1570.attach(p);register_desc_004d1570((void(*)())&callback_impl);}}; Init_004d1570* func_004d1570(){static Init_004d1570 init;return &init;}
