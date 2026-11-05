// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005a1c90(const char*,int); struct Descriptor_005a1c90{void attach(void*);}; extern Descriptor_005a1c90 global_desc_005a1c90; extern void register_desc_005a1c90(void(*)()); extern int name_005a1c90; extern int callback_impl;
struct Init_005a1c90{Init_005a1c90(){void* p=make_desc_005a1c90("Sound",27);global_desc_005a1c90.attach(p);register_desc_005a1c90((void(*)())&callback_impl);}}; Init_005a1c90* func_005a1c90(){static Init_005a1c90 init;return &init;}



