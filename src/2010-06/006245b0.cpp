// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_006245b0(const char*,int); struct Descriptor_006245b0{void attach(void*);}; extern Descriptor_006245b0 global_desc_006245b0; extern void register_desc_006245b0(void(*)()); extern int name_006245b0; extern int callback_impl;
struct Init_006245b0{Init_006245b0(){void* p=make_desc_006245b0((const char*)&name_006245b0,0);global_desc_006245b0.attach(p);register_desc_006245b0((void(*)())&callback_impl);}}; Init_006245b0* func_006245b0(){static Init_006245b0 init;return &init;}
