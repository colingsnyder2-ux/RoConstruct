// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_00599960(const char*,int); struct Descriptor_00599960{void attach(void*);}; extern Descriptor_00599960 global_desc_00599960; extern void register_desc_00599960(void(*)()); extern int name_00599960; extern int callback_impl;
struct Init_00599960{Init_00599960(){void* p=make_desc_00599960("RunService",27);global_desc_00599960.attach(p);register_desc_00599960((void(*)())&callback_impl);}}; Init_00599960* func_00599960(){static Init_00599960 init;return &init;}



