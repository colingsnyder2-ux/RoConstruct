// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3930(const char*,int); struct Descriptor_005b3930{void attach(void*);}; extern Descriptor_005b3930 global_desc_005b3930; extern void register_desc_005b3930(void(*)()); extern int name_005b3930; extern int callback_impl;
struct Init_005b3930{Init_005b3930(){void* p=make_desc_005b3930("Camera",2);global_desc_005b3930.attach(p);register_desc_005b3930((void(*)())&callback_impl);}}; Init_005b3930* func_005b3930(){static Init_005b3930 init;return &init;}

