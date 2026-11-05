// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5220(const char*,int); struct Descriptor_005b5220{void attach(void*);}; extern Descriptor_005b5220 global_desc_005b5220; extern void register_desc_005b5220(void(*)()); extern int name_005b5220; extern int callback_impl;
struct Init_005b5220{Init_005b5220(){void* p=make_desc_005b5220((const char*)&name_005b5220,0);global_desc_005b5220.attach(p);register_desc_005b5220((void(*)())&callback_impl);}}; Init_005b5220* func_005b5220(){static Init_005b5220 init;return &init;}
