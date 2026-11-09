// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004b04b0(const char*,int); struct Descriptor_004b04b0{void attach(void*);}; extern Descriptor_004b04b0 global_desc_004b04b0; extern void register_desc_004b04b0(void(*)()); extern int name_004b04b0; extern int callback_impl;
struct Init_004b04b0{Init_004b04b0(){void* p=make_desc_004b04b0((const char*)&name_004b04b0,0);global_desc_004b04b0.attach(p);register_desc_004b04b0((void(*)())&callback_impl);}}; Init_004b04b0* func_004b04b0(){static Init_004b04b0 init;return &init;}
