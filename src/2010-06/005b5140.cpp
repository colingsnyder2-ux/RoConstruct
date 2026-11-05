// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5140(const char*,int); struct Descriptor_005b5140{void attach(void*);}; extern Descriptor_005b5140 global_desc_005b5140; extern void register_desc_005b5140(void(*)()); extern int name_005b5140; extern int callback_impl;
struct Init_005b5140{Init_005b5140(){void* p=make_desc_005b5140((const char*)&name_005b5140,0);global_desc_005b5140.attach(p);register_desc_005b5140((void(*)())&callback_impl);}}; Init_005b5140* func_005b5140(){static Init_005b5140 init;return &init;}
