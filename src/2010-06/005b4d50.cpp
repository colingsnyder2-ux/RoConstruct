// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4d50(const char*,int); struct Descriptor_005b4d50{void attach(void*);}; extern Descriptor_005b4d50 global_desc_005b4d50; extern void register_desc_005b4d50(void(*)()); extern int name_005b4d50; extern int callback_impl;
struct Init_005b4d50{Init_005b4d50(){void* p=make_desc_005b4d50((const char*)&name_005b4d50,0);global_desc_005b4d50.attach(p);register_desc_005b4d50((void(*)())&callback_impl);}}; Init_005b4d50* func_005b4d50(){static Init_005b4d50 init;return &init;}
