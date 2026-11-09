// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_00624470(const char*,int); struct Descriptor_00624470{void attach(void*);}; extern Descriptor_00624470 global_desc_00624470; extern void register_desc_00624470(void(*)()); extern int name_00624470; extern int callback_impl;
struct Init_00624470{Init_00624470(){void* p=make_desc_00624470((const char*)&name_00624470,0);global_desc_00624470.attach(p);register_desc_00624470((void(*)())&callback_impl);}}; Init_00624470* func_00624470(){static Init_00624470 init;return &init;}
