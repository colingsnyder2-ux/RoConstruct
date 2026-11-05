// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004af7c0(const char*,int); struct Descriptor_004af7c0{void attach(void*);}; extern Descriptor_004af7c0 global_desc_004af7c0; extern void register_desc_004af7c0(void(*)()); extern int name_004af7c0; extern int callback_impl;
struct Init_004af7c0{Init_004af7c0(){void* p=make_desc_004af7c0((const char*)&name_004af7c0,0);global_desc_004af7c0.attach(p);register_desc_004af7c0((void(*)())&callback_impl);}}; Init_004af7c0* func_004af7c0(){static Init_004af7c0 init;return &init;}
