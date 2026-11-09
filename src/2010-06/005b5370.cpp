// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5370(const char*,int); struct Descriptor_005b5370{void attach(void*);}; extern Descriptor_005b5370 global_desc_005b5370; extern void register_desc_005b5370(void(*)()); extern int name_005b5370; extern int callback_impl;
struct Init_005b5370{Init_005b5370(){void* p=make_desc_005b5370((const char*)&name_005b5370,0);global_desc_005b5370.attach(p);register_desc_005b5370((void(*)())&callback_impl);}}; Init_005b5370* func_005b5370(){static Init_005b5370 init;return &init;}
