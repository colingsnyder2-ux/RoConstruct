// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0058f130(const char*,int); struct Descriptor_0058f130{void attach(void*);}; extern Descriptor_0058f130 global_desc_0058f130; extern void register_desc_0058f130(void(*)()); extern int name_0058f130; extern int callback_impl;
struct Init_0058f130{Init_0058f130(){void* p=make_desc_0058f130("TaskScheduler",27);global_desc_0058f130.attach(p);register_desc_0058f130((void(*)())&callback_impl);}}; Init_0058f130* func_0058f130(){static Init_0058f130 init;return &init;}



