// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_004c8120(const char*,int); struct Descriptor_004c8120{void attach(void*);}; extern Descriptor_004c8120 global_desc_004c8120; extern void register_desc_004c8120(void(*)()); extern int name_004c8120; extern int callback_impl;
struct Init_004c8120{Init_004c8120(){void* p=make_desc_004c8120((const char*)&name_004c8120,0);global_desc_004c8120.attach(p);register_desc_004c8120((void(*)())&callback_impl);}}; Init_004c8120* func_004c8120(){static Init_004c8120 init;return &init;}
