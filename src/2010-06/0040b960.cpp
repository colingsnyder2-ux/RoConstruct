// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0040b960(const char*,int); struct Descriptor_0040b960{void attach(void*);}; extern Descriptor_0040b960 global_desc_0040b960; extern void register_desc_0040b960(void(*)()); extern int name_0040b960; extern int callback_impl;
struct Init_0040b960{Init_0040b960(){void* p=make_desc_0040b960((const char*)&name_0040b960,0);global_desc_0040b960.attach(p);register_desc_0040b960((void(*)())&callback_impl);}}; Init_0040b960* func_0040b960(){static Init_0040b960 init;return &init;}
