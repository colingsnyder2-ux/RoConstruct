// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004493a0(const char*,int); struct Descriptor_004493a0{void attach(void*);}; extern Descriptor_004493a0 global_desc_004493a0; extern void register_desc_004493a0(void(*)()); extern int name_004493a0; extern int callback_impl;
struct Init_004493a0{Init_004493a0(){void* p=make_desc_004493a0((const char*)&name_004493a0,0);global_desc_004493a0.attach(p);register_desc_004493a0((void(*)())&callback_impl);}}; Init_004493a0* func_004493a0(){static Init_004493a0 init;return &init;}
