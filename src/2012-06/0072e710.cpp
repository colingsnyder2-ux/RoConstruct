// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_0072e710; extern int s_0072e710; extern int (*cb_0072e710)(void*,void*,int); extern "C" void helper_0072e710(int,void*);
void* func_0072e710() { if(g_0072e710==0 && s_0072e710!=0x29 && cb_0072e710 && !cb_0072e710((void*)0xb42fa8,(void*)0xb440b8,253)) helper_0072e710(g_0072e710,(void*)0xb44040); return (void*)0xe18968; }
