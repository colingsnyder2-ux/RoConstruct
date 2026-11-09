// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4960(const char*,int); struct Descriptor_005b4960{void attach(void*);}; extern Descriptor_005b4960 global_desc_005b4960; extern void register_desc_005b4960(void(*)()); extern int name_005b4960; extern int callback_impl;
struct Init_005b4960{Init_005b4960(){void* p=make_desc_005b4960((const char*)&name_005b4960,0);global_desc_005b4960.attach(p);register_desc_005b4960((void(*)())&callback_impl);}}; Init_005b4960* func_005b4960(){static Init_005b4960 init;return &init;}
