// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004ad810(const char*,int); struct Descriptor_004ad810{void attach(void*);}; extern Descriptor_004ad810 global_desc_004ad810; extern void register_desc_004ad810(void(*)()); extern int name_004ad810; extern int callback_impl;
struct Init_004ad810{Init_004ad810(){void* p=make_desc_004ad810("Player",19);global_desc_004ad810.attach(p);register_desc_004ad810((void(*)())&callback_impl);}}; Init_004ad810* func_004ad810(){static Init_004ad810 init;return &init;}



