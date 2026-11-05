// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_008c6800; extern int s_008c6800; extern int (*cb_008c6800)(void*,void*,int); extern "C" void helper_008c6800(int,void*);
void* func_008c6800() { if(g_008c6800==0 && s_008c6800!=0x29 && cb_008c6800 && !cb_008c6800((void*)0xb42fa8,(void*)0xb440b8,253)) helper_008c6800(g_008c6800,(void*)0xb44040); return (void*)0xe48d14; }
