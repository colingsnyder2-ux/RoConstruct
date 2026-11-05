// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005a71a0(const char*,int); struct Descriptor_005a71a0{void attach(void*);}; extern Descriptor_005a71a0 global_desc_005a71a0; extern void register_desc_005a71a0(void(*)()); extern int name_005a71a0; extern int callback_impl;
struct Init_005a71a0{Init_005a71a0(){void* p=make_desc_005a71a0("Team",27);global_desc_005a71a0.attach(p);register_desc_005a71a0((void(*)())&callback_impl);}}; Init_005a71a0* func_005a71a0(){static Init_005a71a0 init;return &init;}



