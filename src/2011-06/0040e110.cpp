// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0040e110(const char*,int); struct Descriptor_0040e110{void attach(void*);}; extern Descriptor_0040e110 global_desc_0040e110; extern void register_desc_0040e110(void(*)()); extern int name_0040e110; extern int callback_impl;
struct Init_0040e110{Init_0040e110(){void* p=make_desc_0040e110("Authoring",27);global_desc_0040e110.attach(p);register_desc_0040e110((void(*)())&callback_impl);}}; Init_0040e110* func_0040e110(){static Init_0040e110 init;return &init;}



