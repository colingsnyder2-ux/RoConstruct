// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5b50(const char*,int); struct Descriptor_005b5b50{void attach(void*);}; extern Descriptor_005b5b50 global_desc_005b5b50; extern void register_desc_005b5b50(void(*)()); extern int name_005b5b50; extern int callback_impl;
struct Init_005b5b50{Init_005b5b50(){void* p=make_desc_005b5b50((const char*)&name_005b5b50,0);global_desc_005b5b50.attach(p);register_desc_005b5b50((void(*)())&callback_impl);}}; Init_005b5b50* func_005b5b50(){static Init_005b5b50 init;return &init;}
