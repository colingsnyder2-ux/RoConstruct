// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_008ca700; extern int s_008ca700; extern int (*cb_008ca700)(void*,void*,int); extern "C" void helper_008ca700(int,void*);
void* func_008ca700() { if(g_008ca700==0 && s_008ca700!=0x29 && cb_008ca700 && !cb_008ca700((void*)0xb42fa8,(void*)0xb440b8,253)) helper_008ca700(g_008ca700,(void*)0xb44040); return (void*)0xe48adc; }
