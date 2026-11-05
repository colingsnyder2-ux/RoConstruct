// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004db200(const char*,int); struct Descriptor_004db200{void attach(void*);}; extern Descriptor_004db200 global_desc_004db200; extern void register_desc_004db200(void(*)()); extern int name_004db200; extern int callback_impl;
struct Init_004db200{Init_004db200(){void* p=make_desc_004db200((const char*)&name_004db200,0);global_desc_004db200.attach(p);register_desc_004db200((void(*)())&callback_impl);}}; Init_004db200* func_004db200(){static Init_004db200 init;return &init;}
