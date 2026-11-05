// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4030(const char*,int); struct Descriptor_005b4030{void attach(void*);}; extern Descriptor_005b4030 global_desc_005b4030; extern void register_desc_005b4030(void(*)()); extern int name_005b4030; extern int callback_impl;
struct Init_005b4030{Init_005b4030(){void* p=make_desc_005b4030((const char*)&name_005b4030,0);global_desc_005b4030.attach(p);register_desc_005b4030((void(*)())&callback_impl);}}; Init_005b4030* func_005b4030(){static Init_005b4030 init;return &init;}
