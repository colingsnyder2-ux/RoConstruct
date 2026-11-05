// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b7440(const char*,int); struct Descriptor_005b7440{void attach(void*);}; extern Descriptor_005b7440 global_desc_005b7440; extern void register_desc_005b7440(void(*)()); extern int name_005b7440; extern int callback_impl;
struct Init_005b7440{Init_005b7440(){void* p=make_desc_005b7440((const char*)&name_005b7440,0);global_desc_005b7440.attach(p);register_desc_005b7440((void(*)())&callback_impl);}}; Init_005b7440* func_005b7440(){static Init_005b7440 init;return &init;}
