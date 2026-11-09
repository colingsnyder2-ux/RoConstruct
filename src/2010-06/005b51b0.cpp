// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b51b0(const char*,int); struct Descriptor_005b51b0{void attach(void*);}; extern Descriptor_005b51b0 global_desc_005b51b0; extern void register_desc_005b51b0(void(*)()); extern int name_005b51b0; extern int callback_impl;
struct Init_005b51b0{Init_005b51b0(){void* p=make_desc_005b51b0((const char*)&name_005b51b0,0);global_desc_005b51b0.attach(p);register_desc_005b51b0((void(*)())&callback_impl);}}; Init_005b51b0* func_005b51b0(){static Init_005b51b0 init;return &init;}
