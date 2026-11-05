// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b47a0(const char*,int); struct Descriptor_005b47a0{void attach(void*);}; extern Descriptor_005b47a0 global_desc_005b47a0; extern void register_desc_005b47a0(void(*)()); extern int name_005b47a0; extern int callback_impl;
struct Init_005b47a0{Init_005b47a0(){void* p=make_desc_005b47a0((const char*)&name_005b47a0,0);global_desc_005b47a0.attach(p);register_desc_005b47a0((void(*)())&callback_impl);}}; Init_005b47a0* func_005b47a0(){static Init_005b47a0 init;return &init;}
