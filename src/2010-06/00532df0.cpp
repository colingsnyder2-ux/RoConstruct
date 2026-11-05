// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_00532df0(const char*,int); struct Descriptor_00532df0{void attach(void*);}; extern Descriptor_00532df0 global_desc_00532df0; extern void register_desc_00532df0(void(*)()); extern int name_00532df0; extern int callback_impl;
struct Init_00532df0{Init_00532df0(){void* p=make_desc_00532df0((const char*)&name_00532df0,0);global_desc_00532df0.attach(p);register_desc_00532df0((void(*)())&callback_impl);}}; Init_00532df0* func_00532df0(){static Init_00532df0 init;return &init;}
