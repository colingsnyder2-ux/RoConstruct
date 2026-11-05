// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0040b480(const char*,int); struct Descriptor_0040b480{void attach(void*);}; extern Descriptor_0040b480 global_desc_0040b480; extern void register_desc_0040b480(void(*)()); extern int name_0040b480; extern int callback_impl;
struct Init_0040b480{Init_0040b480(){void* p=make_desc_0040b480((const char*)&name_0040b480,0);global_desc_0040b480.attach(p);register_desc_0040b480((void(*)())&callback_impl);}}; Init_0040b480* func_0040b480(){static Init_0040b480 init;return &init;}
