// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6480(const char*,int); struct Descriptor_005b6480{void attach(void*);}; extern Descriptor_005b6480 global_desc_005b6480; extern void register_desc_005b6480(void(*)()); extern int name_005b6480; extern int callback_impl;
struct Init_005b6480{Init_005b6480(){void* p=make_desc_005b6480((const char*)&name_005b6480,0);global_desc_005b6480.attach(p);register_desc_005b6480((void(*)())&callback_impl);}}; Init_005b6480* func_005b6480(){static Init_005b6480 init;return &init;}
