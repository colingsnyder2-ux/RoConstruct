// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4420(const char*,int); struct Descriptor_005b4420{void attach(void*);}; extern Descriptor_005b4420 global_desc_005b4420; extern void register_desc_005b4420(void(*)()); extern int name_005b4420; extern int callback_impl;
struct Init_005b4420{Init_005b4420(){void* p=make_desc_005b4420((const char*)&name_005b4420,0);global_desc_005b4420.attach(p);register_desc_005b4420((void(*)())&callback_impl);}}; Init_005b4420* func_005b4420(){static Init_005b4420 init;return &init;}
