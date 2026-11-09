// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_00444150(const char*,int); struct Descriptor_00444150{void attach(void*);}; extern Descriptor_00444150 global_desc_00444150; extern void register_desc_00444150(void(*)()); extern int name_00444150; extern int callback_impl;
struct Init_00444150{Init_00444150(){void* p=make_desc_00444150((const char*)&name_00444150,0);global_desc_00444150.attach(p);register_desc_00444150((void(*)())&callback_impl);}}; Init_00444150* func_00444150(){static Init_00444150 init;return &init;}
