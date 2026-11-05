// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005a18b0(const char*,int); struct Descriptor_005a18b0{void attach(void*);}; extern Descriptor_005a18b0 global_desc_005a18b0; extern void register_desc_005a18b0(void(*)()); extern int name_005a18b0; extern int callback_impl;
struct Init_005a18b0{Init_005a18b0(){void* p=make_desc_005a18b0("SoundService",27);global_desc_005a18b0.attach(p);register_desc_005a18b0((void(*)())&callback_impl);}}; Init_005a18b0* func_005a18b0(){static Init_005a18b0 init;return &init;}



