// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004d1340(const char*,int); struct Descriptor_004d1340{void attach(void*);}; extern Descriptor_004d1340 global_desc_004d1340; extern void register_desc_004d1340(void(*)()); extern int name_004d1340; extern int callback_impl;
struct Init_004d1340{Init_004d1340(){void* p=make_desc_004d1340((const char*)&name_004d1340,0);global_desc_004d1340.attach(p);register_desc_004d1340((void(*)())&callback_impl);}}; Init_004d1340* func_004d1340(){static Init_004d1340 init;return &init;}
