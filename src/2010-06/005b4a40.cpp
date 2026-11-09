// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4a40(const char*,int); struct Descriptor_005b4a40{void attach(void*);}; extern Descriptor_005b4a40 global_desc_005b4a40; extern void register_desc_005b4a40(void(*)()); extern int name_005b4a40; extern int callback_impl;
struct Init_005b4a40{Init_005b4a40(){void* p=make_desc_005b4a40((const char*)&name_005b4a40,0);global_desc_005b4a40.attach(p);register_desc_005b4a40((void(*)())&callback_impl);}}; Init_005b4a40* func_005b4a40(){static Init_005b4a40 init;return &init;}
