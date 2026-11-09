// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_008cc930; extern int s_008cc930; extern int (*cb_008cc930)(void*,void*,int); extern "C" void helper_008cc930(int,void*);
void* func_008cc930() { if(g_008cc930==0 && s_008cc930!=0x29 && cb_008cc930 && !cb_008cc930((void*)0xb42fa8,(void*)0xb440b8,253)) helper_008cc930(g_008cc930,(void*)0xb44040); return (void*)0xe48ae8; }
