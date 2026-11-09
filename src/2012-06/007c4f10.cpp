// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_007c4f10; extern int s_007c4f10; extern int (*cb_007c4f10)(void*,void*,int); extern "C" void helper_007c4f10(int,void*);
void* func_007c4f10() { if(g_007c4f10==0 && s_007c4f10!=0x29 && cb_007c4f10 && !cb_007c4f10((void*)0xb42fa8,(void*)0xb440b8,253)) helper_007c4f10(g_007c4f10,(void*)0xb44040); return (void*)0xe1df7c; }
