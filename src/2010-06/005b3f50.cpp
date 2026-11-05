// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3f50(const char*,int); struct Descriptor_005b3f50{void attach(void*);}; extern Descriptor_005b3f50 global_desc_005b3f50; extern void register_desc_005b3f50(void(*)()); extern int name_005b3f50; extern int callback_impl;
struct Init_005b3f50{Init_005b3f50(){void* p=make_desc_005b3f50((const char*)&name_005b3f50,0);global_desc_005b3f50.attach(p);register_desc_005b3f50((void(*)())&callback_impl);}}; Init_005b3f50* func_005b3f50(){static Init_005b3f50 init;return &init;}
