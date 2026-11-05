// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5a70(const char*,int); struct Descriptor_005b5a70{void attach(void*);}; extern Descriptor_005b5a70 global_desc_005b5a70; extern void register_desc_005b5a70(void(*)()); extern int name_005b5a70; extern int callback_impl;
struct Init_005b5a70{Init_005b5a70(){void* p=make_desc_005b5a70((const char*)&name_005b5a70,0);global_desc_005b5a70.attach(p);register_desc_005b5a70((void(*)())&callback_impl);}}; Init_005b5a70* func_005b5a70(){static Init_005b5a70 init;return &init;}
