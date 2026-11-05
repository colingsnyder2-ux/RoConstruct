// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_0065c640(const char*,int); struct Descriptor_0065c640{void attach(void*);}; extern Descriptor_0065c640 global_desc_0065c640; extern void register_desc_0065c640(void(*)()); extern int name_0065c640; extern int callback_impl;
struct Init_0065c640{Init_0065c640(){void* p=make_desc_0065c640("RunningAverageItemDouble",27);global_desc_0065c640.attach(p);register_desc_0065c640((void(*)())&callback_impl);}}; Init_0065c640* func_0065c640(){static Init_0065c640 init;return &init;}



