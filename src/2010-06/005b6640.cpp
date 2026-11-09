// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b6640(const char*,int); struct Descriptor_005b6640{void attach(void*);}; extern Descriptor_005b6640 global_desc_005b6640; extern void register_desc_005b6640(void(*)()); extern int name_005b6640; extern int callback_impl;
struct Init_005b6640{Init_005b6640(){void* p=make_desc_005b6640("GuiService",2);global_desc_005b6640.attach(p);register_desc_005b6640((void(*)())&callback_impl);}}; Init_005b6640* func_005b6640(){static Init_005b6640 init;return &init;}

