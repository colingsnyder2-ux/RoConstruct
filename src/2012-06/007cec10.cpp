// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_007cec10; extern int s_007cec10; extern int (*cb_007cec10)(void*,void*,int); extern "C" void helper_007cec10(int,void*);
void* func_007cec10() { if(g_007cec10==0 && s_007cec10!=0x29 && cb_007cec10 && !cb_007cec10((void*)0xb42fa8,(void*)0xb440b8,253)) helper_007cec10(g_007cec10,(void*)0xb44040); return (void*)0xe21510; }
