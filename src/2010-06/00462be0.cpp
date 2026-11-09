// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_00462be0(const char*,int); struct Descriptor_00462be0{void attach(void*);}; extern Descriptor_00462be0 global_desc_00462be0; extern void register_desc_00462be0(void(*)()); extern int name_00462be0; extern int callback_impl;
struct Init_00462be0{Init_00462be0(){void* p=make_desc_00462be0((const char*)&name_00462be0,0);global_desc_00462be0.attach(p);register_desc_00462be0((void(*)())&callback_impl);}}; Init_00462be0* func_00462be0(){static Init_00462be0 init;return &init;}
