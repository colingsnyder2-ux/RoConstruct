// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_007b6750; extern int s_007b6750; extern int (*cb_007b6750)(void*,void*,int); extern "C" void helper_007b6750(int,void*);
void* func_007b6750() { if(g_007b6750==0 && s_007b6750!=0x29 && cb_007b6750 && !cb_007b6750((void*)0xb42fa8,(void*)0xb440b8,253)) helper_007b6750(g_007b6750,(void*)0xb44040); return (void*)0xe1dce8; }
