// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_00469190(const char*,int); struct Descriptor_00469190{void attach(void*);}; extern Descriptor_00469190 global_desc_00469190; extern void register_desc_00469190(void(*)()); extern int name_00469190; extern int callback_impl;
struct Init_00469190{Init_00469190(){void* p=make_desc_00469190((const char*)&name_00469190,0);global_desc_00469190.attach(p);register_desc_00469190((void(*)())&callback_impl);}}; Init_00469190* func_00469190(){static Init_00469190 init;return &init;}
