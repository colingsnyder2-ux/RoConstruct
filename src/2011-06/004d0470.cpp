// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004d0470(const char*,int); struct Descriptor_004d0470{void attach(void*);}; extern Descriptor_004d0470 global_desc_004d0470; extern void register_desc_004d0470(void(*)()); extern int name_004d0470; extern int callback_impl;
struct Init_004d0470{Init_004d0470(){void* p=make_desc_004d0470("Players",27);global_desc_004d0470.attach(p);register_desc_004d0470((void(*)())&callback_impl);}}; Init_004d0470* func_004d0470(){static Init_004d0470 init;return &init;}



