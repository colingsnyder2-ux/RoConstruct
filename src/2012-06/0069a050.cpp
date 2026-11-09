// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_0069a050; extern int s_0069a050; extern int (*cb_0069a050)(void*,void*,int); extern "C" void helper_0069a050(int,void*);
void* func_0069a050() { if(g_0069a050==0 && s_0069a050!=0x29 && cb_0069a050 && !cb_0069a050((void*)0xb42fa8,(void*)0xb440b8,253)) helper_0069a050(g_0069a050,(void*)0xb44040); return (void*)0xe164b4; }
