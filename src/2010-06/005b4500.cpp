// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4500(const char*,int); struct Descriptor_005b4500{void attach(void*);}; extern Descriptor_005b4500 global_desc_005b4500; extern void register_desc_005b4500(void(*)()); extern int name_005b4500; extern int callback_impl;
struct Init_005b4500{Init_005b4500(){void* p=make_desc_005b4500((const char*)&name_005b4500,0);global_desc_005b4500.attach(p);register_desc_005b4500((void(*)())&callback_impl);}}; Init_005b4500* func_005b4500(){static Init_005b4500 init;return &init;}
