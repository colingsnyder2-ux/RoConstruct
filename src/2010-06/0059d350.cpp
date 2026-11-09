// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0059d350(const char*,int); struct Descriptor_0059d350{void attach(void*);}; extern Descriptor_0059d350 global_desc_0059d350; extern void register_desc_0059d350(void(*)()); extern int name_0059d350; extern int callback_impl;
struct Init_0059d350{Init_0059d350(){void* p=make_desc_0059d350((const char*)&name_0059d350,0);global_desc_0059d350.attach(p);register_desc_0059d350((void(*)())&callback_impl);}}; Init_0059d350* func_0059d350(){static Init_0059d350 init;return &init;}
