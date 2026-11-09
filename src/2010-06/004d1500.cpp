// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004d1500(const char*,int); struct Descriptor_004d1500{void attach(void*);}; extern Descriptor_004d1500 global_desc_004d1500; extern void register_desc_004d1500(void(*)()); extern int name_004d1500; extern int callback_impl;
struct Init_004d1500{Init_004d1500(){void* p=make_desc_004d1500((const char*)&name_004d1500,0);global_desc_004d1500.attach(p);register_desc_004d1500((void(*)())&callback_impl);}}; Init_004d1500* func_004d1500(){static Init_004d1500 init;return &init;}
