// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6aa0(const char*,int); struct Descriptor_005b6aa0{void attach(void*);}; extern Descriptor_005b6aa0 global_desc_005b6aa0; extern void register_desc_005b6aa0(void(*)()); extern int name_005b6aa0; extern int callback_impl;
struct Init_005b6aa0{Init_005b6aa0(){void* p=make_desc_005b6aa0((const char*)&name_005b6aa0,0);global_desc_005b6aa0.attach(p);register_desc_005b6aa0((void(*)())&callback_impl);}}; Init_005b6aa0* func_005b6aa0(){static Init_005b6aa0 init;return &init;}
