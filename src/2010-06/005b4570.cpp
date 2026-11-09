// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4570(const char*,int); struct Descriptor_005b4570{void attach(void*);}; extern Descriptor_005b4570 global_desc_005b4570; extern void register_desc_005b4570(void(*)()); extern int name_005b4570; extern int callback_impl;
struct Init_005b4570{Init_005b4570(){void* p=make_desc_005b4570((const char*)&name_005b4570,0);global_desc_005b4570.attach(p);register_desc_005b4570((void(*)())&callback_impl);}}; Init_005b4570* func_005b4570(){static Init_005b4570 init;return &init;}
