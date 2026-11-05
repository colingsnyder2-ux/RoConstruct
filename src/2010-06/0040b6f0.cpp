// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0040b6f0(const char*,int); struct Descriptor_0040b6f0{void attach(void*);}; extern Descriptor_0040b6f0 global_desc_0040b6f0; extern void register_desc_0040b6f0(void(*)()); extern int name_0040b6f0; extern int callback_impl;
struct Init_0040b6f0{Init_0040b6f0(){void* p=make_desc_0040b6f0((const char*)&name_0040b6f0,0);global_desc_0040b6f0.attach(p);register_desc_0040b6f0((void(*)())&callback_impl);}}; Init_0040b6f0* func_0040b6f0(){static Init_0040b6f0 init;return &init;}
