// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3d90(const char*,int); struct Descriptor_005b3d90{void attach(void*);}; extern Descriptor_005b3d90 global_desc_005b3d90; extern void register_desc_005b3d90(void(*)()); extern int name_005b3d90; extern int callback_impl;
struct Init_005b3d90{Init_005b3d90(){void* p=make_desc_005b3d90((const char*)&name_005b3d90,0);global_desc_005b3d90.attach(p);register_desc_005b3d90((void(*)())&callback_impl);}}; Init_005b3d90* func_005b3d90(){static Init_005b3d90 init;return &init;}
