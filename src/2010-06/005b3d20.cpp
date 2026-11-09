// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b3d20(const char*,int); struct Descriptor_005b3d20{void attach(void*);}; extern Descriptor_005b3d20 global_desc_005b3d20; extern void register_desc_005b3d20(void(*)()); extern int name_005b3d20; extern int callback_impl;
struct Init_005b3d20{Init_005b3d20(){void* p=make_desc_005b3d20((const char*)&name_005b3d20,0);global_desc_005b3d20.attach(p);register_desc_005b3d20((void(*)())&callback_impl);}}; Init_005b3d20* func_005b3d20(){static Init_005b3d20 init;return &init;}
