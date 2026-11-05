// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_007a4b40; extern int s_007a4b40; extern int (*cb_007a4b40)(void*,void*,int); extern "C" void helper_007a4b40(int,void*);
void* func_007a4b40() { if(g_007a4b40==0 && s_007a4b40!=0x29 && cb_007a4b40 && !cb_007a4b40((void*)0xb42fa8,(void*)0xb440b8,253)) helper_007a4b40(g_007a4b40,(void*)0xb44040); return (void*)0xe1a92c; }
