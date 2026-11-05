// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_00450bd0(const char*,int); struct Descriptor_00450bd0{void attach(void*);}; extern Descriptor_00450bd0 global_desc_00450bd0; extern void register_desc_00450bd0(void(*)()); extern int name_00450bd0; extern int callback_impl;
struct Init_00450bd0{Init_00450bd0(){void* p=make_desc_00450bd0("ReflectionMetadata",27);global_desc_00450bd0.attach(p);register_desc_00450bd0((void(*)())&callback_impl);}}; Init_00450bd0* func_00450bd0(){static Init_00450bd0 init;return &init;}



