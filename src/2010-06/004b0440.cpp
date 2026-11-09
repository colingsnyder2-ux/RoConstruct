// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004b0440(const char*,int); struct Descriptor_004b0440{void attach(void*);}; extern Descriptor_004b0440 global_desc_004b0440; extern void register_desc_004b0440(void(*)()); extern int name_004b0440; extern int callback_impl;
struct Init_004b0440{Init_004b0440(){void* p=make_desc_004b0440((const char*)&name_004b0440,0);global_desc_004b0440.attach(p);register_desc_004b0440((void(*)())&callback_impl);}}; Init_004b0440* func_004b0440(){static Init_004b0440 init;return &init;}
