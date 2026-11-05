// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b5610(const char*,int); struct Descriptor_005b5610{void attach(void*);}; extern Descriptor_005b5610 global_desc_005b5610; extern void register_desc_005b5610(void(*)()); extern int name_005b5610; extern int callback_impl;
struct Init_005b5610{Init_005b5610(){void* p=make_desc_005b5610((const char*)&name_005b5610,0);global_desc_005b5610.attach(p);register_desc_005b5610((void(*)())&callback_impl);}}; Init_005b5610* func_005b5610(){static Init_005b5610 init;return &init;}
