// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_00590d30(const char*,int); struct Descriptor_00590d30{void attach(void*);}; extern Descriptor_00590d30 global_desc_00590d30; extern void register_desc_00590d30(void(*)()); extern int name_00590d30; extern int callback_impl;
struct Init_00590d30{Init_00590d30(){void* p=make_desc_00590d30((const char*)&name_00590d30,0);global_desc_00590d30.attach(p);register_desc_00590d30((void(*)())&callback_impl);}}; Init_00590d30* func_00590d30(){static Init_00590d30 init;return &init;}
