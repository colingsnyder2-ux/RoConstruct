// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004d12d0(const char*,int); struct Descriptor_004d12d0{void attach(void*);}; extern Descriptor_004d12d0 global_desc_004d12d0; extern void register_desc_004d12d0(void(*)()); extern int name_004d12d0; extern int callback_impl;
struct Init_004d12d0{Init_004d12d0(){void* p=make_desc_004d12d0((const char*)&name_004d12d0,0);global_desc_004d12d0.attach(p);register_desc_004d12d0((void(*)())&callback_impl);}}; Init_004d12d0* func_004d12d0(){static Init_004d12d0 init;return &init;}
