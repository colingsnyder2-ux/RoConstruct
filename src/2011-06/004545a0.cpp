// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004545a0(const char*,int); struct Descriptor_004545a0{void attach(void*);}; extern Descriptor_004545a0 global_desc_004545a0; extern void register_desc_004545a0(void(*)()); extern int name_004545a0; extern int callback_impl;
struct Init_004545a0{Init_004545a0(){void* p=make_desc_004545a0("RenderSettings",27);global_desc_004545a0.attach(p);register_desc_004545a0((void(*)())&callback_impl);}}; Init_004545a0* func_004545a0(){static Init_004545a0 init;return &init;}



