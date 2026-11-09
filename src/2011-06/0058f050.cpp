// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0058f050(const char*,int); struct Descriptor_0058f050{void attach(void*);}; extern Descriptor_0058f050 global_desc_0058f050; extern void register_desc_0058f050(void(*)()); extern int name_0058f050; extern int callback_impl;
struct Init_0058f050{Init_0058f050(){void* p=make_desc_0058f050("DebugSettings",27);global_desc_0058f050.attach(p);register_desc_0058f050((void(*)())&callback_impl);}}; Init_0058f050* func_0058f050(){static Init_0058f050 init;return &init;}



