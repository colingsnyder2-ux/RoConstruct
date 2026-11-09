// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b7360(const char*,int); struct Descriptor_005b7360{void attach(void*);}; extern Descriptor_005b7360 global_desc_005b7360; extern void register_desc_005b7360(void(*)()); extern int name_005b7360; extern int callback_impl;
struct Init_005b7360{Init_005b7360(){void* p=make_desc_005b7360((const char*)&name_005b7360,0);global_desc_005b7360.attach(p);register_desc_005b7360((void(*)())&callback_impl);}}; Init_005b7360* func_005b7360(){static Init_005b7360 init;return &init;}
