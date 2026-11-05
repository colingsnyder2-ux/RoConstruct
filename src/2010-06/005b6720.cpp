// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6720(const char*,int); struct Descriptor_005b6720{void attach(void*);}; extern Descriptor_005b6720 global_desc_005b6720; extern void register_desc_005b6720(void(*)()); extern int name_005b6720; extern int callback_impl;
struct Init_005b6720{Init_005b6720(){void* p=make_desc_005b6720((const char*)&name_005b6720,0);global_desc_005b6720.attach(p);register_desc_005b6720((void(*)())&callback_impl);}}; Init_005b6720* func_005b6720(){static Init_005b6720 init;return &init;}
