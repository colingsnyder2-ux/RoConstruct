// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b7520(const char*,int); struct Descriptor_005b7520{void attach(void*);}; extern Descriptor_005b7520 global_desc_005b7520; extern void register_desc_005b7520(void(*)()); extern int name_005b7520; extern int callback_impl;
struct Init_005b7520{Init_005b7520(){void* p=make_desc_005b7520((const char*)&name_005b7520,0);global_desc_005b7520.attach(p);register_desc_005b7520((void(*)())&callback_impl);}}; Init_005b7520* func_005b7520(){static Init_005b7520 init;return &init;}
