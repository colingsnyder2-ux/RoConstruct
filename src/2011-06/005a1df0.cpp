// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005a1df0(const char*,int); struct Descriptor_005a1df0{void attach(void*);}; extern Descriptor_005a1df0 global_desc_005a1df0; extern void register_desc_005a1df0(void(*)()); extern int name_005a1df0; extern int callback_impl;
struct Init_005a1df0{Init_005a1df0(){void* p=make_desc_005a1df0("StockSound",27);global_desc_005a1df0.attach(p);register_desc_005a1df0((void(*)())&callback_impl);}}; Init_005a1df0* func_005a1df0(){static Init_005a1df0 init;return &init;}



