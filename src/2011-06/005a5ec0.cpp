// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005a5ec0(const char*,int); struct Descriptor_005a5ec0{void attach(void*);}; extern Descriptor_005a5ec0 global_desc_005a5ec0; extern void register_desc_005a5ec0(void(*)()); extern int name_005a5ec0; extern int callback_impl;
struct Init_005a5ec0{Init_005a5ec0(){void* p=make_desc_005a5ec0("RenderHooksService",27);global_desc_005a5ec0.attach(p);register_desc_005a5ec0((void(*)())&callback_impl);}}; Init_005a5ec0* func_005a5ec0(){static Init_005a5ec0 init;return &init;}



