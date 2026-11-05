// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_006360a0(const char*,int); struct Descriptor_006360a0{void attach(void*);}; extern Descriptor_006360a0 global_desc_006360a0; extern void register_desc_006360a0(void(*)()); extern int name_006360a0; extern int callback_impl;
struct Init_006360a0{Init_006360a0(){void* p=make_desc_006360a0("FastLogSettings",27);global_desc_006360a0.attach(p);register_desc_006360a0((void(*)())&callback_impl);}}; Init_006360a0* func_006360a0(){static Init_006360a0 init;return &init;}



