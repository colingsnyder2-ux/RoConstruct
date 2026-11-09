// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_00667c00(const char*,int); struct Descriptor_00667c00{void attach(void*);}; extern Descriptor_00667c00 global_desc_00667c00; extern void register_desc_00667c00(void(*)()); extern int name_00667c00; extern int callback_impl;
struct Init_00667c00{Init_00667c00(){void* p=make_desc_00667c00("ButtonBindingWidget",27);global_desc_00667c00.attach(p);register_desc_00667c00((void(*)())&callback_impl);}}; Init_00667c00* func_00667c00(){static Init_00667c00 init;return &init;}



