// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004db190(const char*,int); struct Descriptor_004db190{void attach(void*);}; extern Descriptor_004db190 global_desc_004db190; extern void register_desc_004db190(void(*)()); extern int name_004db190; extern int callback_impl;
struct Init_004db190{Init_004db190(){void* p=make_desc_004db190((const char*)&name_004db190,0);global_desc_004db190.attach(p);register_desc_004db190((void(*)())&callback_impl);}}; Init_004db190* func_004db190(){static Init_004db190 init;return &init;}
