// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_00590e10(const char*,int); struct Descriptor_00590e10{void attach(void*);}; extern Descriptor_00590e10 global_desc_00590e10; extern void register_desc_00590e10(void(*)()); extern int name_00590e10; extern int callback_impl;
struct Init_00590e10{Init_00590e10(){void* p=make_desc_00590e10((const char*)&name_00590e10,0);global_desc_00590e10.attach(p);register_desc_00590e10((void(*)())&callback_impl);}}; Init_00590e10* func_00590e10(){static Init_00590e10 init;return &init;}
