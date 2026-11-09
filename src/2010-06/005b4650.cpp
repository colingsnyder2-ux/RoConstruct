// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_005b4650(const char*,int); struct Descriptor_005b4650{void attach(void*);}; extern Descriptor_005b4650 global_desc_005b4650; extern void register_desc_005b4650(void(*)()); extern int name_005b4650; extern int callback_impl;
struct Init_005b4650{Init_005b4650(){void* p=make_desc_005b4650((const char*)&name_005b4650,0);global_desc_005b4650.attach(p);register_desc_005b4650((void(*)())&callback_impl);}}; Init_005b4650* func_005b4650(){static Init_005b4650 init;return &init;}
