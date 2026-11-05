// from server: 74% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_007ce360; extern int s_007ce360; extern int (*cb_007ce360)(void*,void*,int); extern "C" void helper_007ce360(int,void*);
void* func_007ce360() { if(g_007ce360==0 && s_007ce360!=0x29 && cb_007ce360 && !cb_007ce360((void*)0xb42fa8,(void*)0xb440b8,253)) helper_007ce360(g_007ce360,(void*)0xb44040); return (void*)0xe21500; }
