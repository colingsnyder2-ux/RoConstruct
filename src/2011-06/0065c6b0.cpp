// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0065c6b0(const char*,int); struct Descriptor_0065c6b0{void attach(void*);}; extern Descriptor_0065c6b0 global_desc_0065c6b0; extern void register_desc_0065c6b0(void(*)()); extern int name_0065c6b0; extern int callback_impl;
struct Init_0065c6b0{Init_0065c6b0(){void* p=make_desc_0065c6b0("ProfilingItem",27);global_desc_0065c6b0.attach(p);register_desc_0065c6b0((void(*)())&callback_impl);}}; Init_0065c6b0* func_0065c6b0(){static Init_0065c6b0 init;return &init;}



