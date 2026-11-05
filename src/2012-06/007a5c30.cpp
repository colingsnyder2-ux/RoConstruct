// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_007a5c30; extern int s_007a5c30; extern int (*cb_007a5c30)(void*,void*,int); extern "C" void helper_007a5c30(int,void*);
void* func_007a5c30() { if(g_007a5c30==0 && s_007a5c30!=0x29 && cb_007a5c30 && !cb_007a5c30((void*)0xb42fa8,(void*)0xb440b8,253)) helper_007a5c30(g_007a5c30,(void*)0xb44040); return (void*)0xe1c1a0; }
