// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004ad190(const char*,int); struct Descriptor_004ad190{void attach(void*);}; extern Descriptor_004ad190 global_desc_004ad190; extern void register_desc_004ad190(void(*)()); extern int name_004ad190; extern int callback_impl;
struct Init_004ad190{Init_004ad190(){void* p=make_desc_004ad190((const char*)&name_004ad190,0);global_desc_004ad190.attach(p);register_desc_004ad190((void(*)())&callback_impl);}}; Init_004ad190* func_004ad190(){static Init_004ad190 init;return &init;}
