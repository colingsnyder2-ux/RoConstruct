// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005af460(const char*,int); struct Descriptor_005af460{void attach(void*);}; extern Descriptor_005af460 global_desc_005af460; extern void register_desc_005af460(void(*)()); extern int name_005af460; extern int callback_impl;
struct Init_005af460{Init_005af460(){void* p=make_desc_005af460("Selection",27);global_desc_005af460.attach(p);register_desc_005af460((void(*)())&callback_impl);}}; Init_005af460* func_005af460(){static Init_005af460 init;return &init;}



